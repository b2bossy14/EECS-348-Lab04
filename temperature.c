#include <stdio.h>

// Function declarations
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorization(float celsius);



int main() {
    // Initialize variables for conversion
    float temp_input;
    float temp_converted;
    int input_scale;
    int output_scale;
    char temp_unit;

    // Get user's temperature value
    printf("\nEnter the temperature: ");
    scanf("%f", &temp_input);

    // Ask user for current scale, and scale to convert to
    do {

        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &input_scale);

        // If user chose Kelvin, make sure their input is not negative
        if (input_scale == 3 && temp_input < 0) {
            printf("\nError: Kelvin temperature cannot be negative. \n");
        }

        // Validate if the input scale is valid
        if (input_scale < 1 || input_scale > 3) {
            printf("\nInvalid input scale.\n");
        }

    // Repeat the loop if Kelvin is negative or the input scale is invalid
    } while ((input_scale < 1 || input_scale > 3) || (input_scale == 3 && temp_input < 0));

    // Loop to get a valid output scale
    // Loop to get a valid output scale
    do {
        printf("\nConvert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &output_scale);

        // Check if the output scale is valid
        // If valid, return an error if the input and output scale are the same
        if (output_scale < 1 || output_scale > 3) {
            printf("\nInvalid output scale.\n");

        } else if (output_scale == input_scale) {
            printf("\nError: Cannot convert to the same scale\n");
            output_scale = 0;
        }

    } while (output_scale < 1 || output_scale > 3);

        




    // Chosen scale is Celsius
    // Based on the output scale, perform conversion
    if (input_scale == 1) { 
        if (output_scale == 1) {
            temp_converted = temp_input; // Celsius to Celsius
            temp_unit = 'C';
        } else if (output_scale == 2) {
            temp_converted = celsius_to_fahrenheit(temp_input); // Celsius to Fahrenheit
            temp_unit = 'F';
        } else if (output_scale == 3) {
            temp_converted = celsius_to_kelvin(temp_input); // Celsius to Kelvin
            temp_unit = 'K';
        }

        // Chosen scale is Fahrenheit
        // Based on the output scale, perform conversion
    } else if (input_scale == 2) { 
        if (output_scale == 1) {
            temp_converted = fahrenheit_to_celsius(temp_input); // Fahrenheit to Celsius
            temp_unit = 'C';

        } else if (output_scale == 2) {
            temp_converted = temp_input; // Fahrenheit to Fahrenheit
            temp_unit = 'F';
        } else if (output_scale == 3) {
            temp_converted = fahrenheit_to_kelvin(temp_input); // Fahrenheit to Kelvin
            temp_unit = 'K';
        }

    // Chosen scale is Kelvin
    // Based on the output scale, perform conversion
    } else if (input_scale == 3) { 
        if (output_scale == 1) {
            temp_converted = kelvin_to_celsius(temp_input); // Kelvin to Celsius
            temp_unit = 'C';
        } else if (output_scale == 2) {
            temp_converted = kelvin_to_fahrenheit(temp_input); // Kelvin to Fahrenheit
            temp_unit = 'F';
        } else if (output_scale == 3) {
            temp_converted = temp_input; // Kelvin to Kelvin
            temp_unit = 'K';
        }        
    } 

    // Print the converted temperature at two deciaml places
    printf("\nConverted temperature: %.2f %c\n", temp_converted, temp_unit);



    // Categorize and provide weather advisory based on the converted temperature in Celsius

    if (output_scale == 1) { 
        // No conversion necessary
        categorization(temp_converted);
    
    } else if (output_scale == 2) { 
        // Converted from F to C and categorize it
        categorization(fahrenheit_to_celsius(temp_converted));

    } else if (output_scale == 3) { 
        // Converted from K to C and categorize it
        categorization(kelvin_to_celsius(temp_converted));
    }

    return 0;
}


// Conversion funtions


// Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

//  Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

//  Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

//  Fahrenheit to Kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

//  Kelvin to Fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}



// Categorize temperature in Celsius
// Print temperature category and a weather advisory
void categorization(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Bundle up\n");

    } else if (celsius >= 0 && celsius <= 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");

    } else if (celsius > 10 && celsius <= 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: It is nice outside.\n");

    } else if (celsius > 25 && celsius <= 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");

    } else if (celsius > 35) {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors.\n");
    }
}
