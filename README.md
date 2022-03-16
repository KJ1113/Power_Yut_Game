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
|team|private|int|:-:|  |val|
|number|private|int|:-:|-|val|
|y|private|int|:-:| |val|
|x|private|int|:-:| |val|
|isChild|private|bool|:-:| |val|
|life|private|bool|:-:| |val|
|child_point|private|*Mal|:-:| |val|
|getNum|public|int|:-:|int|method|
|getTeam|public|int|:-:|int|method|
|getY|public|int|:-:|int|method|
|getX|public|int|:-:|int|method|
|getChild_Cnt|public|int|:-:| |method|
|setTeam|public|void|:-:|int input|method|
|setPos|public|void|:-:|int inputY, int inputX|method|
|setIsChild|public|void|:-:|bool input|method|
|setLife|public|void|:-:|bool input|method|
|setChild|public|void|:-:|Mal *input|method|
|setNum|public|void|:-:|int input|method|
|getIsChild|public|bool|:-:| |method|
|getlife|public|bool|:-:| |method|
|getPointChild|public|*Mal|:-:| |method|

### Board
### Board_Piece

### Game_Manager

### TCP_Network
### IOhandler

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



