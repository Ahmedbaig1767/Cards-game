#include <iostream>
#include <iomanip> 
using namespace std;
void printHand(const int* hand, int size, int player) {
    cout << "Player " << player << "'s hand: ";
    for (int i = 0; i < size; ++i) {
        cout << setw(3) << hand[i] << " ";
    }
    cout << endl;
}

int calculateSum(const int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int deck[52] = { 1,2,3,4,5,6,0,8,9,10,0,10,10,1,2,3,4,5,6,0,8,9,10,0,10,10,1,2,3,4,5,6,0,8,9,10,0,10,10,1,2,3,4,5,6,0,8,9,10,0,10,10 };
    int p1[5], p2[5], p3[5], p4[5], index = 0, open, player = 1, max_index;

    for (int i = 0; i < 5; ++i) {
        p1[i] = deck[index++];
        p2[i] = deck[index++];
        p3[i] = deck[index++];
        p4[i] = deck[index++];
    }
    open = deck[index++];

   
    while (index < 52) {
        int* currentPlayerHand = nullptr;
        string playerName;   
        switch (player) {
        case 1:
            currentPlayerHand = p1;
            playerName = "Player 1";
            break;
        case 2:
            currentPlayerHand = p2;
            playerName = "Player 2";
            break;
        case 3:
            currentPlayerHand = p3;
            playerName = "Player 3";
            break;
        case 4:
            currentPlayerHand = p4;
            playerName = "Player 4";
            break;
        }

        printHand(currentPlayerHand, 5, player);
        cout << "Current open card: " << open << endl;

        int max = currentPlayerHand[0];
        max_index = 0;
        for (int i = 1; i < 5; ++i) {
            if (currentPlayerHand[i] > max) {
                max = currentPlayerHand[i];
                max_index = i;
            }
        }
        if (max > open) {
            cout << playerName << " decides to swap " << max << " with " << open << "." << endl;
            swap(currentPlayerHand[max_index], open);
        }
        else {
            cout << playerName << " decides not to swap. Drawing a new card." << endl;
            open = deck[index++];
            if (max > open) {
                cout << playerName << " swaps " << max << " with the new card " << open << "." << endl;
                swap(currentPlayerHand[max_index], open);
            }
            else {
                cout << "The new card " << open << " is not better than " << max << "." << endl;
            }
        }
        player = (player % 4) + 1;
        cout << "--------------------------------------" << endl;
    }

    int sum1 = calculateSum(p1, 5);
    int sum2 = calculateSum(p2, 5);
    int sum3 = calculateSum(p3, 5);
    int sum4 = calculateSum(p4, 5);

    int minSum = min({ sum1, sum2, sum3, sum4 });

    cout << "Final hands:" << endl;
    printHand(p1, 5, 1);
    printHand(p2, 5, 2);
    printHand(p3, 5, 3);
    printHand(p4, 5, 4);

    cout << "Total sums:" << endl;
    cout << "Player 1 sum: " << sum1 << endl;
    cout << "Player 2 sum: " << sum2 << endl;
    cout << "Player 3 sum: " << sum3 << endl;
    cout << "Player 4 sum: " << sum4 << endl;

    cout << "Minimum sum among all players is = " << minSum << endl;

    return 0;
}
