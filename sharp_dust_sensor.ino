//Dust라는 변수 선언과 미세먼지 값, 습도 값, 온도 값 문자열을 담기위한 배열 선언
int Dust = 0;
char str1[10];                        //미세먼지 값

//각 핀과 연결된 핀 번호를 저장할 변수 선언 
int Vo = A0 ;
int V_LED = 2 ;

//미세먼지값 측정을 위한 데이터값 변수 선언
float Vo_value = 0;
float Voltage = 0;
float a = 0;

void setup(){     
  Serial.begin(9600);
  pinMode(V_LED,OUTPUT);
  pinMode(Vo,INPUT);
}

void loop(){
  Serial.println("ok");

//적외선 발광 다이오드(IRED)와 포토다이오드가 대각선으로 배치되어 공기 중 먼지의 반사광을 감지 
//미세먼지 센서의 데이터값 계산을 통한 미세먼지값 측정
  digitalWrite(V_LED,LOW);
  delayMicroseconds(280);
  Vo_value = analogRead(Vo);
  delayMicroseconds(40);
  digitalWrite(V_LED,HIGH);
  delayMicroseconds(9680);
  
/*
전압[V] = (아날로그 핀 값) * 5.0 / 1024
미세먼지 센서의 출력전압(Vo)는 먼지가 없을 때의 출력전압(Voc)과 미세먼지 농도에 비례하여 출력 
 */
 
  Voltage = Vo_value * 5.0 / 1024.0;
  Serial.println(Voltage);
   if( Voltage < 0.1 ){
    Dust = 0 ;
   } 
   else if ( Voltage < 0.8){
    Dust =10*(5*(Voltage - 0.1));
   }
   else if ( Voltage < 1 ){
    Dust = 10 + 15*((Voltage - 0.8)*10);
   }
   else if( Voltage > 1){
    Dust = 40 + 16*((Voltage - 1)*10);
   }
 Serial.println(Dust);
 delay(500);
}
