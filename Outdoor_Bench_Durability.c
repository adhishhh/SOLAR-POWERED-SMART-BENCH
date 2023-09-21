#include <stdio.h>
#include <stdbool.h>

#define MATERIAL_STRENGTH_THRESHOLD 1000

bool checkBenchDurability(int materialStrength);

int main() {
    int materialStrength;
    
    printf("Enter current material strength: ");
    scanf("%d", &materialStrength);
    
    if (checkBenchDurability(materialStrength)) {
        printf("The bench is durable and weather-resistant.\n");
    } else {
        printf("The bench may not be suitable for outdoor use.\n");
    }
    
    return 0;
}

bool checkBenchDurability(int materialStrength) {
    return materialStrength >= MATERIAL_STRENGTH_THRESHOLD;
}
