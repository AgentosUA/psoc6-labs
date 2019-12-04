# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\User\Desktop\labs\olega\Stepaniuk\lab3\lab_3_2\lab_3_2.cydsn\lab_3_2.cyprj
# Date: Tue, 03 Dec 2019 13:15:08 GMT
#set_units -time ns
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyClk_LF} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyFLL} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/fll}]]
create_clock -name {CyClk_HF0} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/hfclk_0}]]
create_clock -name {CyClk_Fast} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/fastclk}]]
create_clock -name {CyClk_Peri} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/periclk}]]
create_generated_clock -name {CyClk_Slow} -source [get_pins {ClockBlock/periclk}] -edges {1 2 3} [list [get_pins {ClockBlock/slowclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/periclk}] -edges {1 50001 100001} [list [get_pins {ClockBlock/ff_div_11}] [get_pins {ClockBlock/ff_div_12}] [get_pins {ClockBlock/ff_div_13}]]
create_clock -name {CyPeriClk_App} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/periclk_App}]]
create_clock -name {CyIMO} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/imo}]]


# Component constraints for C:\Users\User\Desktop\labs\olega\Stepaniuk\lab3\lab_3_2\lab_3_2.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\User\Desktop\labs\olega\Stepaniuk\lab3\lab_3_2\lab_3_2.cydsn\lab_3_2.cyprj
# Date: Tue, 03 Dec 2019 13:14:46 GMT
