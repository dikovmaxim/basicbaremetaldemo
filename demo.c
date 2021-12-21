__asm__(".code16\n");
__asm__("jmpl $0x0000, $main\n");
int Width = 320;
int Height = 200;

void DrawPixel(unsigned char color, int col, int row) {
     __asm__ __volatile__ (
          "int $0x10" : : "a"(0x0c00 | color), "c"(col), "d"(row)
     );
}

int Devation(int x, int y){
  return (int)floor(x+y/2);
}

void main() {
      __asm__ __volatile__ (
          "int $0x10" : : "a"(0x03)
     );
     __asm__ __volatile__ (
          "int $0x10" : : "a"(0x0013)
     );

     int CenterX = Width/2;
     int CenterY = Height/2;
     int k = 0;
     for(;;){
       k-=3;
       for(int x = 0; x <=Width; x++){ 
	 for(int y = 0; y <=Height; y++){ 
	   int diffx = CenterX - x;
	   int diffy = CenterY - y;
	   if(diffx < 0) diffx = x - CenterX;
	   if(diffy < 0) diffy = y - CenterY;
	   DrawPixel(Devation(diffx,diffy)+k,x,y);
	 }
       }
       if(k > 200) k = 0;
     }
}
