#include <stdio.h>
#include <stdlib.h>

// Définition du noeud
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;  // pointeur global vers la tête

// Création d'un nouveau noeud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation memoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insertion en queue
void insertAtTail(int data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev; // dernier élément
        newNode->next = head;    // le nouveau pointe vers head
        newNode->prev = tail;    // le nouveau pointe vers l'ancien tail
        tail->next = newNode;    // l'ancien tail pointe vers le nouveau
        head->prev = newNode;    // la tête pointe en arrière vers le nouveau
    }
}

// Insertion en tête
void insertAtHead(int data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev; // dernier élément
        newNode->next = head;    // le nouveau pointe vers l'ancienne tête
        newNode->prev = tail;    // le nouveau pointe vers le tail
        tail->next = newNode;    // le tail pointe vers le nouveau
        head->prev = newNode;    // l'ancienne tête pointe vers le nouveau
        head = newNode;          // mise à jour de la tête
    }
}

// Affichage vers l'avant
void displayForward() {
    if (head == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Node* temp = head;
    printf("Parcours avant : ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Affichage vers l'arrière
void displayBackward() {
    if (head == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Node* temp = head->prev; // commencer par la fin
    printf("Parcours arriere : ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("\n");
}

// Vérification du caractère circulaire
void checkCircularity() {
    if (head == NULL) return;

    printf("Verification de la circularite :\n");
    printf("head->data = %d\n", head->data);
    printf("head->prev->data (dernier element) = %d\n", head->prev->data);
    printf("head->prev->next->data (doit etre egal q head->data) = %d\n", head->prev->next->data);
}

int main() {
    int val;

    printf("=== Liste doublement chaînee circulaire ===\n");

    // Initialisation avec des éléments déjà présents
    insertAtTail(10);
    insertAtTail(20);
    insertAtTail(30);

    printf("\nListe initiale :\n");
    displayForward();
    displayBackward();
    checkCircularity();

    // Insertion en tête
    printf("\n--- Insertion en tete ---\n");
    printf("Entrez un entier a inserer en tete : ");
    scanf("%d", &val);
    insertAtHead(val);
    displayForward();
    displayBackward();
    checkCircularity();

    // Insertion en queue
    printf("\n--- Insertion en queue ---\n");
    printf("Entrez un entier a inserer en queue : ");
    scanf("%d", &val);
    insertAtTail(val);
    displayForward();
    displayBackward();
    checkCircularity();

    return 0;
}
