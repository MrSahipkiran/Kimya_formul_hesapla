#include <stdio.h>
#include <stdlib.h>
#include <string.h>
					//ilk sıkıntı eğer kelime 3 harften az ise anlamlı kelımelerden sonrakılerı herhangı bır string yapıyor
	struct stack{
		char icerik[20];
		int carpan;
		struct stack *next;
	};
	//					Magara(OyHr)2
	struct stack *stack1top	=	NULL;
	struct stack *stack2top	=	NULL;


void Listele2(){
	while(1){
		printf("\n%s:%d",stack2top->icerik,stack2top->carpan);
		stack2top=stack2top->next;
		if(stack2top==NULL)break;
	}
}

void Listele1(){
	int control=1;
	while(control==1){
		printf("\n%s:%d",stack1top->icerik,stack1top->carpan);
		stack1top=stack1top->next;
		if(stack1top==NULL)control=0;
	}
}

void FormulHesap(int diziuzunlugu,char dizi[50]){
	int i=0,buyukHarf=0,j=0;
	for(i=0;i<diziuzunlugu;i++){												//uzunluk kadar donguye gırırp tek tek karekterlerı kontrol edecek
	
		if((dizi[i]>=65&&dizi[i]<=90)||(dizi[i]>=97&&dizi[i]<=122)){				//kelime gördüyse(buyuk veya kucuk harf gorduyse yazıyor ıf ıcınde)
			if(dizi[i]>=65&&dizi[i]<=90){											//buyuk harf gorduyse
				
				struct stack *stack1=(struct stack*)malloc(sizeof(struct stack));
				if(i==0&&stack1top==NULL){				//stack1 boşsa ve ilk buyuk harfse								sıra Cu(NaOH) daki C'de ise	+
					stack1->next=NULL;
					stack1->icerik[0]=dizi[0];
					stack1->carpan=1;
					stack1top=stack1;
				}
				else {			//stack1 boş degilse 							sıra Cu(NaOH) daki N'de ise	struct stack *stack1=(struct stack*)malloc(sizeof(struct stack));
					stack1->icerik[0]=dizi[i];
					stack1->next=stack1top;
					stack1top=stack1;
					stack1->carpan=1;
					j=0;
				}
			}
		
			else 	 {							//kucuk harf gorduyse
				j++;
				stack1top->icerik[j]=dizi[i];
			}
		}
		else if(dizi[i]=='('||dizi[i]==')'){										//parantez gorduyse
			if(dizi[i]=='('){														//parentez açılımı gorduyse
				j=0;
				struct stack *stack1=(struct stack*)malloc(sizeof(struct stack));
				stack1->icerik[0]='(';
				stack1->carpan=0;
				stack1->next=stack1top;
				stack1top=stack1;
			}
			
			else{														//parantez kapatımı gorduyse
				int a=1,control=1;j=0;
				while(control==1){
					struct stack *temp=stack1top;
					struct stack *stack2=(struct stack*)malloc(sizeof(struct stack));
					if(stack2top==NULL){//stack2 boşsa
						strcpy(stack2->icerik,stack1top->icerik);
						stack2->carpan=stack1top->carpan;
						stack2->next=NULL;
						stack2top=stack2;
						stack1top=stack1top->next;
						free(temp);
					}
					else{				//stack2 doluysa
						strcpy(stack2->icerik,stack1top->icerik);
						stack2->carpan=stack1top->carpan;
						stack2->next=stack2top;
						stack2top=stack2;
						stack1top=stack1top->next;
					}
					if(stack1top->icerik[0]=='('){
						temp=stack1top;
						stack1top=stack1top->next;
						free(temp);
						control=0;						
					}
				}
			}
		}
		
		else{																		//sayı gördüyse
			int carpan=dizi[i]-48;
			if(stack2top==NULL){	//stack2 boşsa
				stack1top->carpan*=carpan;
				}
				
			else{					//stack2 boş degilse
				struct stack *stack2temp=stack2top;
				int control1=1;
				while(control1==1){
					stack2top->carpan*=carpan;
					struct stack *stack1=(struct stack*)malloc(sizeof(struct stack));
					stack1->carpan=stack2top->carpan;
					strcpy(stack1->icerik,stack2top->icerik);
					stack1->next=stack1top;
					stack1top=stack1;
					stack2temp=stack2top;
					stack2top=stack2top->next;
					free(stack2temp);
					if(stack2top==NULL)control1=0;
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	char cumle[50];
	printf("Formulu giriniz\tornegin:Zn(H2(KP5)3)2\n");
	gets(cumle);
	FormulHesap(strlen(cumle),cumle);
	Listele1();
	return 0;
}