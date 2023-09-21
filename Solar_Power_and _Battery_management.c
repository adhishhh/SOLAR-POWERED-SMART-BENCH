#include <stdio.h>
#include <stdbool.h>

#define DAYLIGHT_THRESHOLD 100
#define BATTERY_CAPACITY 1000

void chargeBattery(int daylightIntensity);
void powerBenchAndRFIDReader();

int main() {
    int daylightIntensity;
    
    printf("Enter current daylight intensity: ");
    scanf("%d", &daylightIntensity);
    
    chargeBattery(daylightIntensity);
    powerBenchAndRFIDReader();
    
    return 0;
}

void chargeBattery(int daylightIntensity) {
    static int batteryCharge = 0;
    if (daylightIntensity > DAYLIGHT_THRESHOLD) {
        batteryCharge += (daylightIntensity - DAYLIGHT_THRESHOLD);
        if (batteryCharge > BATTERY_CAPACITY) {
            batteryCharge = BATTERY_CAPACITY;
        }
    }
    
    printf("Battery charge: %d watt-hours\n", batteryCharge);
}

void powerBenchAndRFIDReader() {
    // Check battery charge status and power the bench and RFID reader
    // ...
    printf("Bench and RFID reader powered.\n");
}
