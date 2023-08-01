library ieee;
use ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.ALL;

entity regfile_ext is
    generic ( 
        dw   : natural := 4;
        size : natural := 4;
        adrw : natural := 2);
    port ( 
        A     : in  std_logic_vector(dw-1 downto 0);
        rAddr1: in  std_logic_vector(adrw-1 downto 0);
        rAddr2: in  std_logic_vector(adrw-1 downto 0);
        wAddr : in  std_logic_vector(adrw-1 downto 0);
        we    : in  std_logic;
        clk   : in  std_logic;
        reset : in  std_logic;
        B     : out std_logic_vector(dw-1 downto 0);
        C     : out std_logic_vector(dw-1 downto 0));
end regfile_ext;

architecture behavioral of regfile_ext is

type regArray is array(0 to size-1) of std_logic_vector(dw-1 downto 0);
signal regfile : regArray;

begin
    process(clk)
    begin
        if (clk'event and clk='0') then
            if we='1' then
                regfile(to_integer(unsigned(wAddr))) <= A;
            end if;
            if reset='1' then
                regfile(0) <= "0000";
                regfile(1) <= "0000";
                regfile(2) <= "0000";
                regfile(3) <= "0000";
            end if ;
        end if;
        B <= regfile(to_integer(unsigned(rAddr1)));
        C <= regfile(to_integer(unsigned(rAddr2)));
    end process;
end behavioral;