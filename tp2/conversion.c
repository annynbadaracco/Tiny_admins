extern long suma(long a, long b);

long conversion(float gini){
    
    long gini_l = (long) gini;
    long result = suma(gini_l, 1);
    return result;
}
