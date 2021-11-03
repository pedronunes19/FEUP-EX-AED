
unsigned fibonacci_1(unsigned n) {  // T:O(2^n)  S:O()
    if (n <= 1)
        return n;
    return fibonacci_1(n-1) + fibonacci_1(n-2);
}

unsigned fibonacci_2(unsigned n) {  // T:O(n)  S:O(1)
    unsigned valPrevPrev = 0, valPrev = 1;
    if (n == 0)
        return valPrevPrev;
    if (n == 1)
        return valPrev;
    unsigned val;
    for (unsigned i = 2; i <= n; i ++)
    {
        val = valPrevPrev + valPrev;
        valPrevPrev = valPrev;
        valPrev = val;
    }
    return val;
}

