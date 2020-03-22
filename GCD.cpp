int gcd(int a,int b){
    if(a<b) swap(a,b);
    while(b!=0){
        a%=b;
        swap(a,b);
    }
    return a;
}
