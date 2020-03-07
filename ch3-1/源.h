#pragma once

void MergeSort(int origin[], int result[], int from, int to);
void copyRemainder(int j, int to, int* temp, int& k, int* result, int& retflag);
void Merge(int result[], int from, int middle, int to);
