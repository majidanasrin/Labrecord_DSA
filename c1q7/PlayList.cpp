#include <iostream>
using namespace std;

struct Song {
    string title;
    string artist;
    int duration;
    string genre;
    Song* next;

    Song(string t, string a, int d, string g) : title(t), artist(a), duration(d), genre(g), next(nullptr) {}
};

Song* merge(Song* left, Song* right, string sortBy) {
    if (!left) return right;
    if (!right) return left;

    Song* result = nullptr;

    if (sortBy == "title") {
        if (left->title <= right->title) {
            result = left;
            result->next = merge(left->next, right, sortBy);
        } else {
            result = right;
            result->next = merge(left, right->next, sortBy);
        }
    } else if (sortBy == "artist") {
        if (left->artist <= right->artist) {
            result = left;
            result->next = merge(left->next, right, sortBy);
        } else {
            result = right;
            result->next = merge(left, right->next, sortBy);
        }
    } else if (sortBy == "duration") {
        if (left->duration <= right->duration) {
            result = left;
            result->next = merge(left->next, right, sortBy);
        } else {
            result = right;
            result->next = merge(left, right->next, sortBy);
        }
    } else { 
        if (left->genre <= right->genre) {
            result = left;
            result->next = merge(left->next, right, sortBy);
        } else {
            result = right;
            result->next = merge(left, right->next, sortBy);
        }
    }

    return result;
}

void splitList(Song* head, Song** left, Song** right) {
    Song* fast;
    Song* slow;
    slow = head;
    fast = head->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = nullptr;
}

void mergeSort(Song** headRef, string sortBy) {
    Song* head = *headRef;
    Song* left;
    Song* right;

    if (!head || !head->next) {
        return;
    }

    splitList(head, &left, &right);

    mergeSort(&left, sortBy);
    mergeSort(&right, sortBy);

    *headRef = merge(left, right, sortBy);
}

void printPlaylist(Song* head) {
    while (head) {
        cout << "Title: " << head->title << "\t Artist: " << head->artist << "\t Duration: " << head->duration << " \t seconds , Genre: " << head->genre << endl;
        head = head->next;
    }
}

int main() {

    Song* head = new Song("Apocalypse", "Cigarettes After Sex", 180, "Alternative");
    head->next = new Song("Wanna Be Yours", "Arctic Monkeys", 240, "Indie Rock");
    head->next->next = new Song("Dark Red", "Steve Lacy", 200, "R&B");
    head->next->next->next = new Song("Careless Whisper", "George Michael", 220, "Pop");

    cout << "Original Playlist:" << endl;
    printPlaylist(head);

    mergeSort(&head, "title"); 
    cout << "\nSorted Playlist by Title:" << endl;
    printPlaylist(head);

    mergeSort(&head, "artist"); 
    cout << "\nSorted Playlist by Artist:" << endl;
    printPlaylist(head);

    mergeSort(&head, "duration"); 
    cout << "\nSorted Playlist by Duration:" << endl;
    printPlaylist(head);

    mergeSort(&head, "genre"); 
    cout << "\nSorted Playlist by Genre:" << endl;
    printPlaylist(head);

    while (head) {
        Song* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
