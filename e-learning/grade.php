<?php 

$count = 0;

$ans1 = $_GET['answer1']; $ans2 = $_GET['answer2'];
$ans3 = $_GET['answer3']; $ans4 = $_GET['answer4'];
$ans5 = $_GET['answer5'];
if ($ans1 == 3){ $count++; }
if ($ans2 == 2){ $count++; }
if ($ans3 == 4){ $count++; }
if ($ans4 == 1){ $count++; }
if ($ans5 == 5){ $count++; }
if ($count == 5){ 
    header('location: success.html');
} else {
    header('location: index.html');
} 
