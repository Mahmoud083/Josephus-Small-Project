#include <stdio.h>
#include <stdlib.h>

void josephus(int n) {
    int people[n];
    for (int i = 0; i < n; i++) {
        people[i] = i + 1; // Initialize the circle
    }
    
    int count = n;       // Number of people remaining
    int index = -1;      // Start index (we'll increment first)
    
    while (count > 1) {
        // Find the next person to eliminate
        int steps = 0;
        while (steps < 2) { // Count two positions for classic Josephus
            index = (index + 1) % n;
            if (people[index] != 0) { // Skip eliminated people
                steps++;
            }
        }
        
        // Eliminate person
        printf("Eliminated: %d\n", people[index]);
        people[index] = 0; // Mark as eliminated
        count--;
    }
    
    // Find the survivor
    for (int i = 0; i < n; i++) {
        if (people[i] != 0) {
            printf("Survivor: %d\n", people[i]);
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_people>\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Number of people must be a positive integer.\n");
        return 1;
    }
    
    josephus(n);
    return 0;
}
