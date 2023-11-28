-- 7 Segments Display design
library IEEE;
use IEEE.std_logic_1164.all;

entity display is
port(
  A: in std_logic;
  B: in std_logic;
  C: in std_logic;
  D: in std_logic;
  a1: out std_logic;
  b1: out std_logic;
  c1: out std_logic;
  d1: out std_logic;
  e1: out std_logic;
  f1: out std_logic;
  g1: out std_logic);
end display;


architecture rtl of display is
begin
  process(A, B, C, D) is
  begin
    case (A, B, C, D) is
      when "0000" => -- Dígito 0
        a1 <= '1';
        b1 <= '1';
        c1 <= '1';
        d1 <= '1';
        e1 <= '1';
        f1 <= '1';
        g1 <= '0';
      when "0001" => -- Dígito 1
        a1 <= '0';
        b1 <= '1';
        c1 <= '1';
        d1 <= '0';
        e1 <= '0';
        f1 <= '0';
        g1 <= '0';
      when "0010" => -- Dígito 2
        a1 <= '1';
        b1 <= '1';
        c1 <= '0';
        d1 <= '1';
        e1 <= '1';
        f1 <= '0';
        g1 <= '1';
      when "0011" => -- Dígito 3
        a1 <= '1';
        b1 <= '1';
        c1 <= '1';
        d1 <= '1';
        e1 <= '0';
        f1 <= '0';
        g1 <= '1';
      when "0100" => -- Dígito 4
        a1 <= '0';
        b1 <= '1';
        c1 <= '1';
        d1 <= '0';
        e1 <= '0';
        f1 <= '1';
        g1 <= '1';
      when "0101" => -- Dígito 5
        a1 <= '1';
        b1 <= '0';
        c1 <= '1';
        d1 <= '1';
        e1 <= '0';
        f1 <= '1';
        g1 <= '1';
      when "0110" => -- Dígito 6
        a1 <= '1';
        b1 <= '0';
        c1 <= '1';
        d1 <= '1';
        e1 <= '1';
        f1 <= '1';
        g1 <= '1';
      when "0111" => -- Dígito 7
        a1 <= '1';
        b1 <= '1';
        c1 <= '1';
        d1 <= '0';
        e1 <= '0';
        f1 <= '0';
        g1 <= '0';
      when "1000" => -- Dígito 8
        a1 <= '1';
        b1 <= '1';
        c1 <= '1';
        d1 <= '1';
        e1 <= '1';
        f1 <= '1';
        g1 <= '1';
      when "1001" => -- Dígito 9
        a1 <= '1';
        b1 <= '1';
        c1 <= '1';
        d1 <= '1';
        e1 <= '0';
        f1 <= '1';
        g1 <= '1';
      when "1010" => -- Dígito A
        a1 <= '1';
        b1 <= '1';
        c1 <= '1';
        d1 <= '0';
        e1 <= '1';
        f1 <= '1';
        g1 <= '1';
      when "1011" => -- Dígito B
        a1 <= '0';
        b1 <= '0';
        c1 <= '1';
        d1 <= '1';
        e1 <= '1';
        f1 <= '1';
        g1 <= '1';
      when "1100" => -- Dígito C
        a1 <= '1';
        b1 <= '0';
        c1 <= '0';
        d1 <= '1';
        e1 <= '1';
        f1 <= '1';
        g1 <= '0';
      when "1101" => -- Dígito D
        a1 <= '0';
        b1 <= '1';
        c1 <= '1';
        d1 <= '1';
        e1 <= '1';
        f1 <= '0';
        g1 <= '1';
      when "1110" => -- Dígito E
        a1 <= '1';
        b1 <= '0';
        c1 <= '0';
        d1 <= '1';
        e1 <= '1';
        f1 <= '1';
        g1 <= '1';
      when others => -- Dígito F
        a1 <= '1';
        b1 <= '0';
        c1 <= '0';
        d1 <= '0';
        e1 <= '1';
        f1 <= '1';
        g1 <= '1';
    end case;
  end process;
end rtl;
