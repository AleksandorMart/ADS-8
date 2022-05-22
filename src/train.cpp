// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
first = nullptr;
countOp = 0;
}

Train::~Train() {
int num = getLength();
Cage* del;
while (num--) {
del = first;
first = first->next;
delete del;
}
}

void Train::addCage(bool light) {
if (first == nullptr) {
first = new Cage;
first->light = light;
first->next = first->prev = nullptr;
} else {
if (!first->next) {
first->next = new Cage;
first->prew = first->next;
first->next->next = first;
first->next->prew = first;
} else {
Cage* current = first->prev;
current->next = new Cage;
current->next->next = first;
current->next->prew = current;
first->prew = current->next;
}
}
}

int Train::getLength() {
Cage* current = first;
current->light = true;
while (true) {
int length_way = 0;
do {
current = current->next;
length_way++;
} while (!current->light);
int length_fixed = length_way;
countOp += length_way;
current->light = false;
While (length_way > 1) {
current = current->prev;
length_way--;
countOp++;
}
length_way = 0;
if (!current->light) {
return length_fixed;
}
}
}

int Train::getOpCount() {
return countOp;
}
