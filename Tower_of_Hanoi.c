# include <stdio.h>

void tower_of_hanoi(int disk, char source, char helper, char destination) {
    if (disk == 1) {
        printf("\nMove disk %d from tower %c to tower %c", disk, source, destination);
        return;
    }
    tower_of_hanoi(disk - 1, source, destination, helper);
    printf("\nMove disk %d from tower %c to tower %c", disk, source, destination);
    tower_of_hanoi(disk - 1, helper, source, destination);
}

int main() {
    int disks;
    printf("Enter the Number of disks :-  ");
    scanf("%d", &disks);
    tower_of_hanoi(disks, 'A', 'B', 'C');
}