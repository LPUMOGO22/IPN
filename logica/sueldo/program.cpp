#include <iostream>

int main() {
   const int BASE = 350;
   const float EXTRA = BASE * 1.5;
   const float RETENCION1 = .12;
   const float RETENCION2 = .18;
   float horas, bruto, neto;

   std::cout<<"¿Cuántas horas trabajó esta semana?\n";
   std::cin>>horas;
   if (horas<=40){
     bruto = horas*BASE;
   }else{
     horas = horas - 40;
     bruto = (40*BASE) + (horas*EXTRA);
   }

    if(bruto <= 10000){
      neto = bruto;
    }else if(bruto>10000 && bruto <=15000){
      bruto = bruto - 10000;
      neto = 10000 + (bruto*(1-RETENCION1));
    }else{
       bruto = bruto - 10000;
       neto = 10000 + (bruto*(1-RETENCION2));

    }

    std::cout<<"El salario neto semanal es de: $"<<neto<<std::endl;

   
    return 0;
}
