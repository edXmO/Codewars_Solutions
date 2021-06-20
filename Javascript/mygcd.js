// Greatest common divisor
function mygcd(x,y){
    if (x == 0) return x;
    if (y == 0) return y;
    
    if(x === y) return x;
    
    if(x > y){
      return mygcd(x - y, y);
    } else {
      return mygcd(x, y - x);
    }
}