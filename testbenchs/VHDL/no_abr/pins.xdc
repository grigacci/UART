set_property IOSTANDARD LVCMOS33 [get_ports clock_y3]
set_property PACKAGE_PIN E3 [get_ports clock_y3]
create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports clock_y3];

set_property IOSTANDARD LVCMOS33 [get_ports usb_rs232_rxd]
set_property PACKAGE_PIN C17 [get_ports usb_rs232_rxd]
set_property PACKAGE_PIN D18 [get_ports usb_rs232_txd]
set_property IOSTANDARD LVCMOS33 [get_ports usb_rs232_txd]
set_property IOSTANDARD LVCMOS33 [get_ports user_reset]
set_property PACKAGE_PIN J15 [get_ports user_reset]

