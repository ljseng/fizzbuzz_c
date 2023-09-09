#include "logr.h"
#include <stdio.h>
#include <string.h>

#define TOTAL_NUMBERS 100
#define MAX_INPUT_CSV_STRING_LENGTH 300
#define MAX_OUTPUT_CSV_STRING_LENGTH 500
#define MAX_OUTPUT_LENGTH 9

/**
 * Perform the FizzBuzz calculations on the input array and store the results in an output array.
 *
 * @param inputs          The input integer array.
 * @param inputsLength    The length of the input array.
 * @param fizzbuzzResults The output array to store the FizzBuzz results.
 */
void fizzbuzz(const int inputs[], size_t inputsLength, char fizzbuzzResults[][MAX_OUTPUT_LENGTH]) {
    for (size_t ii = 0; ii < inputsLength; ii++) {
        char output[MAX_OUTPUT_LENGTH];
        output[0] = '\0';
        if ((inputs[ii] % 5 == 0) && (inputs[ii] % 3 == 0)) {
            strcpy(output, "FizzBuzz");
        } else if (inputs[ii] % 3 == 0) {
            strcpy(output, "Fizz");
        } else if (inputs[ii] % 5 == 0) {
            strcpy(output, "Buzz");
        } else {
            snprintf(output, MAX_OUTPUT_LENGTH, "%d", inputs[ii]);
        }

        strcpy(fizzbuzzResults[ii], output);
    }
}

/**
 * Render the input array as a CSV string and log it.
 *
 * @param inputs       The input integer array.
 * @param inputsLength The length of the input array.
 */
void renderInputs(const int inputs[], size_t inputsLength) {
    char inputsCsv[MAX_INPUT_CSV_STRING_LENGTH];
    inputsCsv[0] = '\0';

    for (size_t ii = 0; ii < inputsLength; ii++) {
        snprintf(inputsCsv + strlen(inputsCsv), MAX_INPUT_CSV_STRING_LENGTH, "%d,", inputs[ii]);
    }
    inputsCsv[strlen(inputsCsv) - 1] = '\0'; // remove the last comma

    logr(LOGR_INFO, "INPUT: [%s]", inputsCsv);
}

/**
 * Render the output array as a CSV string and log it.
 *
 * @param outputs       The output array containing the FizzBuzz results.
 * @param outputsLength The length of the output array.
 */
void renderOutputs(const char outputs[][MAX_OUTPUT_LENGTH], size_t outputsLength) {
    char outputsCsv[MAX_OUTPUT_CSV_STRING_LENGTH];
    outputsCsv[0] = '\0';

    for (size_t ii = 0; ii < outputsLength; ii++) {
        strcat(outputsCsv, outputs[ii]);
        strcat(outputsCsv, ",");
    }
    outputsCsv[strlen(outputsCsv) - 1] = '\0'; // remove the last comma

    logr(LOGR_INFO, "OUTPUT: [%s]", outputsCsv);
}

int main() {
    // create array of 100 elements. values: 1,2,3,...,100
    int inputs[TOTAL_NUMBERS];
    for (size_t ii=0; ii<TOTAL_NUMBERS; ii++) {
        inputs[ii] = ii + 1;
    }

    renderInputs(inputs, TOTAL_NUMBERS);

    char fizzbuzzResults[TOTAL_NUMBERS][MAX_OUTPUT_LENGTH];
    fizzbuzz(inputs, TOTAL_NUMBERS, fizzbuzzResults);

    renderOutputs(fizzbuzzResults, TOTAL_NUMBERS);
}
