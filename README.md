# Power_Yut_Game

## C++ Console 환경에서 진행되는 윷놀이 게임!!

### **플레이 LIST**
  * 싱글 플레이
  * 멀티 플레이
  * 인공지능 플레이
<br/>

### **싱글 플레이**
1. 두명의 사용자가 하나의 PC를 이용하여 진행합니다.
2. 윷 던지기 화면이 나오면 Enter Key 를 이용하여 윷을 던집니다.
3. 3개의 말을 선택할수있으며 (시작시점 기준) 상황에 따라 **상대팀 말을 잡거나, 같은팀 말과 결합할수도** 있습니다.
4. 3개의 말이 모두 결승선에 도착하는 팀이 승리합니다.
5. 윷 판위의 " ◎ " 위치는 다음턴에 무조건 대각선으로 이동합니다.
6. 백도는 없습니다.
<br/>

### **멀티 플레이**
1. 두명의 사용자가 두대의 PC로 플레이합니다.
2. 방장이 먼저 방을 만들면, 참여자가 방장 IP 주소를 입력하여 참가합니다.
3. 플레이 방법은 싱글플레이와 같습니다.
4. 상대편이 선택하는 동안 대기 시간이 있습니다.
<br/>

### **인공지능 플레이**
1. 사용자는 RED 팀, 인공지능은 BLUE 팀으로 시작합니다.
2. 인공지능 턴일때, 인공지능이 자동으로 말을 선택하고 이동합니다.
3. 인공지능은 말을 업거나, 상대편 말을 잡는것을 좋아합니다.
4. 인공지능은 대각선으로 이동할수있는 위치를 선호합니다.
<br/>

***
## Class List

### Player
>게임 참여자 Class

|이름|접근자|Type|설명|Parameter|비고|
|:-:|:-:|:-:|:-:|:-:|:-:|
|team|Private|int|플레이어 팀, 0 과 1로 구분한다.|Parameter|val|
|score|Private|int|플레이어 현재 스코어|Parameter|val|
|mal|Private|Mal[3]|플레이어가 보유한 말 배열, Size 3 |Parameter|val|
|getTeam|Public|int|플레이어 팀 number 반환|Parameter|method|
|getScore|Public|int|플레이어 점수 반환|Parameter|method|
|getMal|Public|Mal|Index Parameter 를 이용하여 사용자 말[index] 반환|Parameter|method|
|setTeam|Public|void|팀 number 부여|Parameter|method|
|setScore|Public|void|점수 부여|Parameter|method|

### AI
>AI 모드 실행시 사용되는 Class

|이름|접근자|Type|설명|Parameter|비고|
|:-:|:-:|:-:|:-:|:-:|:-:|
|getSelectMal|public|int|알고리즘에 따라서 선택된 말 반환|Player& player, Board& board, int yut_num|method|
|getMoveValue|public|int|말판의 위치에 따른 가중치 값 반환|Mal*mal, Board& board, int yut_num|method|
|getChildValue|public|int|자식유무에 따른 가중치 값 반환|Mal* mal|method|
|getTeamValue|public|int|말잡기, 합치기에 따른 가중치 값 반환|Mal* mal, Board& board, int yut_num|method|


### Mal
>보드위에서 움직이는 Mal Class, 포인터를 활용하여 잡기,합치기 구현.

|이름|접근자|Type|설명|Parameter|비고|
|:-:|:-:|:-:|:-:|:-:|:-:|
|team|private|int|팀|  |val|
|number|private|int|말 번호|-|val|
|y|private|int|말판에서 y축 좌표| |val|
|x|private|int|말판에서 x축 좌표| |val|
|isChild|private|bool|자식 유무, 있다면 true| |val|
|life|private|bool|생존여부, 마지막 위치에 도착하면 false| |val|
|child_point|private|*Mal|자식 연결 포인터| |val|
|getNum|public|int|말 번호 반환|int|method|
|getTeam|public|int|팀 반환|int|method|
|getY|public|int|:-:|y 축 반환|method|
|getX|public|int|:-:|x 축 반환|method|
|getChild_Cnt|public|int|연결된 자식 말 갯수 반환| |method|
|getIsChild|public|bool|자식 유무 반환| |method|
|getlife|public|bool|생존 유무 반환| |method|
|getPointChild|public|*Mal|자식말 포인터 반환| |method|
|setTeam|public|void|팀 입력/int input|method|
|setPos|public|void|위치 입력|int inputY, int inputX|method|
|setIsChild|public|void|자식 유무 입력|bool input|method|
|setLife|public|void|생존 여부 입력|bool input|method|
|setChild|public|void|자식이 될 말 입력|Mal *input|method|
|setNum|public|void|말번호 입력|int input|method|


### Board
> 보드 Class.

|이름|접근자|Type|설명|Parameter|비고|
|:-:|:-:|:-:|:-:|:-:|:-:|
|bp|private|Board_Piece[11][11]|Board_Piece class 를 11 * 11 배열로 만든것| |val|
|getBoardPiece|public|&Board_Piece|각 위치에 맞는 Board_Piece 주소값 반환 |int y , int x|method|
|getMovePoint|public|pair<int, int>|말의 상황별 이동위치 반환 |int y ,int x, int yut_num|method|
|init_Piece|public|void|팀| Board 초기화 |method|
|endPoint_Init|public|void|말이 마지막 위치 도달하면 Board_Piece 초기화 |Mal* point_mal|method|


### Board_Piece
> 보드 조각 Class.

|이름|접근자|Type|설명|Parameter|비고|
|:-:|:-:|:-:|:-:|:-:|:-:|
|isMove|private|bool|말이 이동가능한 위치 0 , 1| |val|
|mal|private|*Mal|말판위에 말이 놓이면 연결됨| |val|
|getIsMove|public|bool|이동유무 반환| |method|
|getMalPoint|public|*Mal|현재 말판조각위의 말 포인터 반환| |method|
|setMal|public|void|말 포인터 입력|Mal* tmp|method|
|setIsMove|public|void|초기 이동유무 설정|bool input|method|
|init_Piece|public|void|초기화 함수| |method|
|linkedPoint|public|int|mal 변수와 연결, 0 또는 1을 반환하여 상대편말을 잡았는지 알려준다.|Mal* m|method|
|connectPoint|public|void|재귀 함수를 이용하여 말포인터를 연결한다.|Mal* tmp, Mal* m|method|
|disConnectPoint|public|void|연결 해제|Mal* m|method|


### Game_Manager
> 게임 진행 관련 Class.
[Game_Manager.h 이동] (링크)


### TCP_Network
> TCP 네트워크 Class.
[TCP_Network.h 이동] (링크)

### IOhandler
> 입출력 관련 Class.
[IOhandler.h 이동] (링크)

***
## UI

|메뉴|이미지|
|:-:|:-:|
|메뉴|<img src ="https://user-images.githubusercontent.com/37038119/157171458-e5b73ea1-d605-4359-9d48-57f0a7efb702.png" width = "500px">|
|윷던지기|<img src ="https://user-images.githubusercontent.com/37038119/157171911-9a02f17d-e38b-43a8-8fe7-3d8248735fe3.png" width = "500px">|
|말 선택|<img src ="https://user-images.githubusercontent.com/37038119/157172120-f74e17dc-fdfe-400d-909a-27d82eb4b12c.png" width = "500px">|
|이동위치 확인|<img src ="https://user-images.githubusercontent.com/37038119/157171969-ac4fcaa6-adea-440d-8b3a-7ad933f07c1d.png" width = "500px">|

***
## 멀티 플레이 설정

|설명|이미지|
|:-:|:-:|
|멀티 플레이 선택|<img src ="https://user-images.githubusercontent.com/37038119/158515818-a44d5396-816b-4ee3-b3db-733574680d1d.png" width = "500px">|
|방장은 "0" 입력|<img src ="https://user-images.githubusercontent.com/37038119/158515820-c153a2f1-d3f4-456e-9d77-440440ca3533.png" width = "500px">|
|참여자는 "1" 입력후 IP 주소입력|<img src ="https://user-images.githubusercontent.com/37038119/158515824-0493215f-4feb-432c-b6d0-dfde3d29c6db.png" width = "500px">|



