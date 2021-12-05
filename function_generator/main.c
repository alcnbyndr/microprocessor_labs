/*
 * main.c
 *
 * author: Alican Bayındır
 *
 * Button # will be used as an Enter key
 * Button * will be used as a dot key
 * Button A will be used to define the Amplitudeof the signal.
 * It will expect a series of numbers after it, and upon pressing the Enter key, it will apply the amplitude.
 * E.g. A1 * 20 # will set the amplitude to 1.20 Volts Peak-Peak.
 * Button Bwill be used to define the Frequencyof the signal.
 * It will expect a series of numbers after it, and upon pressing the Enter key,
 * it will apply the frequency. E.g.B120#will set the frequency to 120Hz.
 * There should be proper guards for voltage/amplitude inputs and other buttons
 * (i.e.Pressing Bafter Ashould cancel the operation)○If no button is pressed for 10seconds,
 * timeout should happen,and input should be cancelled.
 * Button Cwill cycle through modes.
 * Button Dwill cycle through displaying the Mode, Amplitude and Frequency of the currently active signal.
 * Sine, square, triangle, sawtooth,and white noisemodes should accept both amplitude and frequency information.
 * Digital stream outputmode should randomly generate 0 and 1s at the given frequency.
 * The amplitude should not affect the amplitude of this operation. This should use a different output pin
 * than the one used for other modes.
 * All operations should be shown on the SSDs.○By default,the SSD should display the mode. Sine, square,
 * triangle, sawtooth (ramp), white noise and random digital stream modes. (try to spell each uniquely. ie.
 * for sine, you can write SInE, for triangle, you can write trI,  etc.)
 * Pressing button A should empty the SSD and each digit press should push the digit from left and shift
 * the others to the left. . (dot) should be displayed as one digit character of your choosing)
 * Pressing Enter should clear the SSD and should go back to displaying the mode.
 * There should be no bouncing on the buttons.
 * There should be no brightness difference between Seven Segments.
 * There should be no flickering on the SSDs.
 * You should calculate and figure out the maximum possible frequencies that you can run.
 * Output signals should be clean,so design proper filters based on the frequency range that you support.
 */

#include "stm32g0xx.h"
#include "bsp.h"

int main(void) {

    return 0;
}

