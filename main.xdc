##  Switches
#########################################################################################################################
set_property -dict { PACKAGE_PIN J15   IOSTANDARD LVCMOS33 } [get_ports { SW[0] }]; 
set_property -dict { PACKAGE_PIN L16   IOSTANDARD LVCMOS33 } [get_ports { SW[1] }]; 
set_property -dict { PACKAGE_PIN M13   IOSTANDARD LVCMOS33 } [get_ports { SW[2] }]; 
set_property -dict { PACKAGE_PIN R15   IOSTANDARD LVCMOS33 } [get_ports { SW[3] }]; 
set_property -dict { PACKAGE_PIN R17   IOSTANDARD LVCMOS33 } [get_ports { SW[4] }]; 
set_property -dict { PACKAGE_PIN T18   IOSTANDARD LVCMOS33 } [get_ports { SW[5] }]; 
set_property -dict { PACKAGE_PIN U18   IOSTANDARD LVCMOS33 } [get_ports { SW[6] }]; 
set_property -dict { PACKAGE_PIN R13   IOSTANDARD LVCMOS33 } [get_ports { SW[7] }]; 
set_property -dict { PACKAGE_PIN T8    IOSTANDARD LVCMOS18 } [get_ports { SW[8] }]; 
set_property -dict { PACKAGE_PIN U8    IOSTANDARD LVCMOS18 } [get_ports { SW[9] }]; 
set_property -dict { PACKAGE_PIN R16   IOSTANDARD LVCMOS33 } [get_ports { SW[10] }]; 
set_property -dict { PACKAGE_PIN T13   IOSTANDARD LVCMOS33 } [get_ports { SW[11] }]; 
set_property -dict { PACKAGE_PIN H6    IOSTANDARD LVCMOS33 } [get_ports { SW[12] }]; 
set_property -dict { PACKAGE_PIN U12   IOSTANDARD LVCMOS33 } [get_ports { SW[13] }]; 
set_property -dict { PACKAGE_PIN U11   IOSTANDARD LVCMOS33 } [get_ports { SW[14] }]; 
set_property -dict { PACKAGE_PIN V10   IOSTANDARD LVCMOS33 } [get_ports { SW[15] }]; 
#########################################################################################################################
#########################################################################################################################
## Clock signal
set_property -dict { PACKAGE_PIN E3    IOSTANDARD LVCMOS33 } [get_ports { w_clk }];
create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports {w_clk}];


##### 240x240 ST7789 mini display #####
#########################################################################################################################
###### Pmod Header JXDAC
set_property -dict { PACKAGE_PIN A13   IOSTANDARD LVCMOS33 } [get_ports { st7789_DC  }]; # Pmod JXDAC1
set_property -dict { PACKAGE_PIN A15   IOSTANDARD LVCMOS33 } [get_ports { st7789_RES }]; # Pmod JXDAC2
set_property -dict { PACKAGE_PIN B16   IOSTANDARD LVCMOS33 } [get_ports { st7789_SDA }]; # Pmod JXDAC3
set_property -dict { PACKAGE_PIN B18   IOSTANDARD LVCMOS33 } [get_ports { st7789_SCL }]; # Pmod JXDAC4

###### Pmod Header JA
## set_property -dict { PACKAGE_PIN C17   IOSTANDARD LVCMOS33 } [get_ports { st7789_DC  }]; # Pmod JA1
## set_property -dict { PACKAGE_PIN D18   IOSTANDARD LVCMOS33 } [get_ports { st7789_RES }]; # Pmod JA2
## set_property -dict { PACKAGE_PIN E18   IOSTANDARD LVCMOS33 } [get_ports { st7789_SDA }]; # Pmod JA3
## set_property -dict { PACKAGE_PIN G17   IOSTANDARD LVCMOS33 } [get_ports { st7789_SCL }]; # Pmod JA4

###### Pmod Header JB
## set_property -dict { PACKAGE_PIN D14   IOSTANDARD LVCMOS33 } [get_ports { st7789_DC  }]; # Pmod JB1
## set_property -dict { PACKAGE_PIN F16   IOSTANDARD LVCMOS33 } [get_ports { st7789_RES }]; # Pmod JB2
## set_property -dict { PACKAGE_PIN G16   IOSTANDARD LVCMOS33 } [get_ports { st7789_SDA }]; # Pmod JB3
## set_property -dict { PACKAGE_PIN H14   IOSTANDARD LVCMOS33 } [get_ports { st7789_SCL }]; # Pmod JB4

###### Pmod Header JC
## set_property -dict { PACKAGE_PIN K1    IOSTANDARD LVCMOS33 } [get_ports { st7789_DC  }]; # Pmod JC1
## set_property -dict { PACKAGE_PIN F6    IOSTANDARD LVCMOS33 } [get_ports { st7789_RES }]; # Pmod JC2
## set_property -dict { PACKAGE_PIN J2    IOSTANDARD LVCMOS33 } [get_ports { st7789_SDA }]; # Pmod JC3
## set_property -dict { PACKAGE_PIN G6    IOSTANDARD LVCMOS33 } [get_ports { st7789_SCL }]; # Pmod JC4

###### Pmod Header JD
## set_property -dict { PACKAGE_PIN H4    IOSTANDARD LVCMOS33 } [get_ports { st7789_DC  }]; # Pmod JD1
## set_property -dict { PACKAGE_PIN H1    IOSTANDARD LVCMOS33 } [get_ports { st7789_RES }]; # Pmod JD2
## set_property -dict { PACKAGE_PIN G1    IOSTANDARD LVCMOS33 } [get_ports { st7789_SDA }]; # Pmod JD3
## set_property -dict { PACKAGE_PIN G3    IOSTANDARD LVCMOS33 } [get_ports { st7789_SCL }]; # Pmod JD4
#########################################################################################################################

## LEDs
set_property -dict {PACKAGE_PIN H17 IOSTANDARD LVCMOS33} [get_ports {led[0]}]
set_property -dict {PACKAGE_PIN K15 IOSTANDARD LVCMOS33} [get_ports {led[1]}]
set_property -dict {PACKAGE_PIN J13 IOSTANDARD LVCMOS33} [get_ports {led[2]}]
set_property -dict {PACKAGE_PIN N14 IOSTANDARD LVCMOS33} [get_ports {led[3]}]
set_property -dict {PACKAGE_PIN R18 IOSTANDARD LVCMOS33} [get_ports {led[4]}]
set_property -dict {PACKAGE_PIN V17 IOSTANDARD LVCMOS33} [get_ports {led[5]}]
set_property -dict {PACKAGE_PIN U17 IOSTANDARD LVCMOS33} [get_ports {led[6]}]
set_property -dict {PACKAGE_PIN U16 IOSTANDARD LVCMOS33} [get_ports {led[7]}]
set_property -dict {PACKAGE_PIN V16 IOSTANDARD LVCMOS33} [get_ports {led[8]}]
set_property -dict {PACKAGE_PIN T15 IOSTANDARD LVCMOS33} [get_ports {led[9]}]
set_property -dict {PACKAGE_PIN U14 IOSTANDARD LVCMOS33} [get_ports {led[10]}]
set_property -dict {PACKAGE_PIN T16 IOSTANDARD LVCMOS33} [get_ports {led[11]}]
set_property -dict {PACKAGE_PIN V15 IOSTANDARD LVCMOS33} [get_ports {led[12]}]
set_property -dict {PACKAGE_PIN V14 IOSTANDARD LVCMOS33} [get_ports {led[13]}]
set_property -dict {PACKAGE_PIN V12 IOSTANDARD LVCMOS33} [get_ports {led[14]}]
set_property -dict {PACKAGE_PIN V11 IOSTANDARD LVCMOS33} [get_ports {led[15]}]

##  Switches
#########################################################################################################################
#set_property -dict { PACKAGE_PIN J15   IOSTANDARD LVCMOS33 } [get_ports { SW[0] }]; 
#set_property -dict { PACKAGE_PIN L16   IOSTANDARD LVCMOS33 } [get_ports { SW[1] }]; 
#set_property -dict { PACKAGE_PIN M13   IOSTANDARD LVCMOS33 } [get_ports { SW[2] }]; 
#set_property -dict { PACKAGE_PIN R15   IOSTANDARD LVCMOS33 } [get_ports { SW[3] }]; 
#set_property -dict { PACKAGE_PIN R17   IOSTANDARD LVCMOS33 } [get_ports { SW[4] }]; 
#set_property -dict { PACKAGE_PIN T18   IOSTANDARD LVCMOS33 } [get_ports { SW[5] }]; 
#set_property -dict { PACKAGE_PIN U18   IOSTANDARD LVCMOS33 } [get_ports { SW[6] }]; 
#set_property -dict { PACKAGE_PIN R13   IOSTANDARD LVCMOS33 } [get_ports { SW[7] }]; 
#set_property -dict { PACKAGE_PIN T8    IOSTANDARD LVCMOS18 } [get_ports { SW[8] }]; 
#set_property -dict { PACKAGE_PIN U8    IOSTANDARD LVCMOS18 } [get_ports { SW[9] }]; 
#set_property -dict { PACKAGE_PIN R16   IOSTANDARD LVCMOS33 } [get_ports { SW[10] }]; 
#set_property -dict { PACKAGE_PIN T13   IOSTANDARD LVCMOS33 } [get_ports { SW[11] }]; 
#set_property -dict { PACKAGE_PIN H6    IOSTANDARD LVCMOS33 } [get_ports { SW[12] }]; 
#set_property -dict { PACKAGE_PIN U12   IOSTANDARD LVCMOS33 } [get_ports { SW[13] }]; 
#set_property -dict { PACKAGE_PIN U11   IOSTANDARD LVCMOS33 } [get_ports { SW[14] }]; 
#set_property -dict { PACKAGE_PIN V10   IOSTANDARD LVCMOS33 } [get_ports { SW[15] }]; 
#########################################################################################################################