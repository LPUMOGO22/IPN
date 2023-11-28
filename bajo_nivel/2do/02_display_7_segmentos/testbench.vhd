library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
-- empty
end testbench;

architecture tb of testbench is

  -- DUT component
  component display is
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
      g1: out std_logic
    );
  end component;

  signal A, B, C, D: std_logic := '0';
  signal a_out, b_out, c_out, d_out, e_out, f_out, g_out: std_logic;

begin

  -- Instantiate DUT
  DUT: display port map(A, B, C, D, a_out, b_out, c_out, d_out, e_out, f_out, g_out);

  -- Test cases
  process
  begin
    -- Test para 0
    A <= '0';
    B <= '0';
    C <= '0';
    D <= '0';
    wait for 10 ns;
    assert (a_out = '1' and b_out = '1' and c_out = '1' and d_out = '1' and e_out = '1' and f_out = '1' and g_out = '0') 
      report "Fallo para 0" severity error;
    -- Test para 1
    A <= '0';
    B <= '0';
    C <= '0';
    D <= '1';
    wait for 10 ns;
    assert (a_out = '0' and b_out = '1' and c_out = '1' and d_out = '0' and e_out = '0' and f_out = '0' and g_out = '0') 
      report "Fallo para 1" severity error;
    -- Test para 2
    A <= '0';
    B <= '0';
    C <= '1';
    D <= '0';
    wait for 10 ns;
    assert (a_out = '1' and b_out = '1' and c_out = '0' and d_out = '1' and e_out = '1' and f_out = '0' and g_out = '1') 
      report "Fallo para 2" severity error;
    -- Test para 3
    A <= '0';
    B <= '0';
    C <= '1';
    D <= '1';
    wait for 10 ns;
    assert (a_out = '1' and b_out = '1' and c_out = '1' and d_out = '1' and e_out = '0' and f_out = '0' and g_out = '1') 
      report "Fallo para 3" severity error;
    -- Test para 4
    A <= '0';
    B <= '1';
    C <= '0';
    D <= '0';
    wait for 10 ns;
    assert (a_out = '0' and b_out = '1' and c_out = '1' and d_out = '0' and e_out = '0' and f_out = '1' and g_out = '1') 
      report "Fallo para 4" severity error;
    -- Test para 5
    A <= '0';
    B <= '1';
    C <= '0';
    D <= '1';
    wait for 10 ns;
    assert (a_out = '1' and b_out = '0' and c_out = '1' and d_out = '1' and e_out = '0' and f_out = '1' and g_out = '1') 
      report "Fallo para 5" severity error;
    -- Test para 6
    A <= '0';
    B <= '1';
    C <= '1';
    D <= '0';
    wait for 10 ns;
    assert (a_out = '1' and b_out = '0' and c_out = '1' and d_out = '1' and e_out = '1' and f_out = '1' and g_out = '1') 
      report "Fallo para 6" severity error;
    -- Test para 7
    A <= '0';
    B <= '1';
    C <= '1';
    D <= '1';
    wait for 10 ns;
    assert (a_out = '1' and b_out = '1' and c_out = '1' and d_out = '0' and e_out = '0' and f_out = '0' and g_out = '1') 
      report "Fallo para 7" severity error;
    -- Test para 8
    A <= '1';
    B <= '0';
    C <= '0';
    D <= '0';
    wait for 10 ns;
    assert (a_out = '1' and b_out = '1' and c_out = '1' and d_out = '1' and e_out = '1' and f_out = '1' and g_out = '1') 
      report "Fallo para 8" severity error;
    -- Test para 9
    A <= '1';
    B <= '0';
    C <= '0';
    D <= '1';
    wait for 10 ns;
    assert (a_out = '1' and b_out = '1' and c_out = '1' and d_out = '0' and e_out = '0' and f_out = '1' and g_out = '1') 
      report "Fallo para 9" severity error;
    -- Test para A
    A <= '1';
    B <= '0';
    C <= '1';
    D <= '0';
    wait for 10 ns;
    assert (a_out = '1' and b_out = '1' and c_out = '1' and d_out = '0' and e_out = '1' and f_out = '1' and g_out = '1') 
      report "Fallo para A" severity error;
    -- Test para B
    A <= '1';
    B <= '0';
    C <= '1';
    D <= '1';
    wait for 10 ns;
    assert (a_out = '0' and b_out = '0' and c_out = '1' and d_out = '1' and e_out = '1' and f_out = '1' and g_out = '1') 
      report "Fallo para B" severity error;
    -- Test para C
    A <= '1';
    B <= '1';
    C <= '0';
    D <= '0';
    wait for 10 ns;
    assert (a_out = '1' and b_out = '0' and c_out = '0' and d_out = '1' and e_out = '1' and f_out = '1' and g_out = '0') 
      report "Fallo para C" severity error;
    -- Test para D
    A <= '1';
    B <= '1';
    C <= '0';
    D <= '1';
    wait for 10 ns;
    assert (a_out = '0' and b_out = '1' and c_out = '1' and d_out = '1' and e_out = '1' and f_out = '0' and g_out = '1') 
      report "Fallo para D" severity error;
    -- Test para E
    A <= '1';
    B <= '1';
    C <= '1';
    D <= '0';
    wait for 10 ns;
    assert (a_out = '1' and b_out = '0' and c_out = '0' and d_out = '1' and e_out = '1' and f_out = '1' and g_out = '1') 
      report "Fallo para E" severity error;
    -- Test para F
    A <= '1';
    B <= '1';
    C <= '1';
    D <= '1';
    wait for 10 ns;
    assert (a_out = '1' and b_out = '0' and c_out = '0' and d_out = '0' and e_out = '1' and f_out = '1' and g_out = '1') 
      report "Fallo para F" severity error;

    assert false report "TODO BIEN" severity note;
    wait;
  end process;

end tb;
