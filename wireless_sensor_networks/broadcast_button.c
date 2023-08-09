#include "contiki.h"
#include "net/rime.h"
#include "random.h"
#include "dev/light-sensor.h"
#include "dev/button-sensor.h"
#include "dev/leds.h"
#include "sys/node-id.h"
#include <stdio.h>
PROCESS(broadcast_button_process, "Broadcast Button");
AUTOSTART_PROCESSES(&broadcast_button_process);

int button_pressed_counter=0; //δήλωση μετρητή για τον αριθμό που πατήθηκε το κουμπί
int messages_received_counter=0; //δήλωση μετρητή για τον αριθμό που λήφθηκε μήνυμα
//συνάρτηση για τα εισερχόμενα broadcast
static void broadcast_recv(struct broadcast_conn *c, const rimeaddr_t *from)
{
	 messages_received_counter++; //μόλις ληφθεί μήνυμα ,αυξάνει τον μετρητή ληφθέντων μηνυμάτων

	//τυπώνει το μήνυμα που λήφθηκε και τον αποστολέα του
	 printf("Broadcast message received from %d.%d: '%s'\n", from->u8[0], from->u8[1], (char*)packetbuf_dataptr());
	
	//τυπώνει τον αριθμό των ληφθέντων μηνυμάτων με βάση τον μετρητή στην αρχή
	 printf("Button pressed on node %d.%d - %d messages received in total\n", from->u8[0], from->u8[1], messages_received_counter);
	
	//αλλάζει την κατάσταση των πράσινων και μπλε led
	 leds_toggle(LEDS_GREEN);
	 leds_toggle(LEDS_BLUE);
}
static const struct broadcast_callbacks broadcast_call = {broadcast_recv};
static struct broadcast_conn broadcast;
PROCESS_THREAD(broadcast_button_process, ev, data)
{
 static struct etimer timer; //αρχική δήλωση του timer
 
 PROCESS_EXITHANDLER(broadcast_close(&broadcast);)
 PROCESS_BEGIN();
 
 SENSORS_ACTIVATE(button_sensor); //ενεργοποίηση του αισθητήρα

 broadcast_open(&broadcast, 129, &broadcast_call); //άνοιγμα της broadcast σύνδεσης σε συγκεκριμένο channel
 while(1) //ατέρμων βρόγχος γιατί είναι συνέχεια 1 δηλαδή true
 {
	 PROCESS_WAIT_EVENT_UNTIL(ev == sensors_event && data==&button_sensor); //αναμονή μέχρι να πατηθεί το κουμπί
	 
	 button_pressed_counter++; //μόλις πατηθεί αυξάνει τον μετρητή
	 
	 printf("Node %d: my button was pressed - it has been pressed %d times in total\n", node_id, button_pressed_counter); //τυπώνει μήνυμα για το mote id address και τον αριθμό φορών που πατήθηκε σύμφωνα με τον μετρητή
	 
	 leds_on(LEDS_RED); //ανάβει τα κόκκινα led
	 
	 //θέτει τον timer για 5 δεύτερα
	 etimer_set(&timer, CLOCK_SECOND * 5);
	 
	 PROCESS_WAIT_EVENT_UNTIL(ev == PROCESS_EVENT_TIMER); //και μόλις λήξει ο timer,δηλαδή να περάσουν τα 5 δεύτερα
	 
	 leds_off(LEDS_RED); //σβήνει τα κόκκινα led
	 //κάνει broadcast το μήνυμα button pressed στους υπόλοιπους
	 packetbuf_copyfrom("button pressed", 16);
	 broadcast_send(&broadcast);
 }
 PROCESS_END();
}