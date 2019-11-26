# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\student\FeS-31\Stepaniuk\lab4\lab4_1\lab4_1.cydsn\lab4_1.cyprj
# Date: Wed, 02 Oct 2019 14:51:06 GMT
#set_units -time ns
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyClk_LF} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyFLL} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/fll}]]
create_clock -name {CyClk_HF0} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/hfclk_0}]]
create_clock -name {CyClk_Fast} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/fastclk}]]
create_clock -name {CyClk_Peri} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/periclk}]]
create_generated_clock -name {CyClk_Slow} -source [get_pins {ClockBlock/periclk}] -edges {1 2 3} [list [get_pins {ClockBlock/slowclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/periclk}] -edges {1 51 101} [list [get_pins {ClockBlock/ff_div_11}] [get_pins {ClockBlock/ff_div_12}]]
create_clock -name {CyPeriClk_App} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/periclk_App}]]
create_clock -name {CyIMO} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/imo}]]


# Component constraints for D:\student\FeS-31\Stepaniuk\lab4\lab4_1\lab4_1.cydsn\TopDesign\TopDesign.cysch
# Project: D:\student\FeS-31\Stepaniuk\lab4\lab4_1\lab4_1.cydsn\lab4_1.cyprj
# Date: Wed, 02 Oct 2019 14:50:51 GMT
