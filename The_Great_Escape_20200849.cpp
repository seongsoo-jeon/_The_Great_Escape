#include <bangtal.h>

SceneID title, scene1_0, scene1_1;
SceneID scene20, scene21, scene22, scene23, scene24;
SceneID scene30, scene31, scene32, scene33, scene34;
SceneID scene40, scene41;
SceneID ask;
SceneID run1;
SceneID ask1, ask2, ask2_2, askre, ask3, ask4;
SceneID title2, exit, final1;

SoundID theme, asd, foot, foot2, a1, a2, a3, a4, wolff, wolfff, open, glass;

TimerID timer1;

ObjectID startbutton, endbutton, act1, key, Scene1, Scene1_1;
ObjectID Scene20, Scene21, Scene22, Scene23, Scene24;
ObjectID front1, front2, front3, front4, back1, back2, back3, back4, back5;
ObjectID front5, front6, front7, front8, front9;
ObjectID asker, asker2, Run1;
ObjectID door1, door2;
ObjectID ask1_1;
ObjectID wolf, wolf1, wolf2, wolf3, wolf4;
ObjectID ask2_3;
ObjectID door3;
ObjectID Scene40, Scene41;
ObjectID class1, book, pensil, dic;
ObjectID asker3, askerre, ask4_1, exit1, umb, final2;

bool closed1 = true;
bool closed2 = true;

ObjectID CreateObject(const char* image, SceneID scene, int x, int y) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	showObject(object);
	return object;
}
void makeback() {
	back1 = CreateObject("뒤로간다.png", scene20, 530, 10);
	back2 = CreateObject("뒤로간다.png", scene21, 530, 10);
	back3 = CreateObject("뒤로간다.png", scene22, 530, 10);
	back4 = CreateObject("뒤로간다.png", scene23, 530, 10);
	back5 = CreateObject("뒤로간다.png", scene24, 530, 10);
}
void hidefront1() {
	hideObject(front1);
	hideObject(front2);
	hideObject(front3);
	hideObject(front4);
}
void rest() {
	stopTimer(timer1);
	hideTimer();
	setTimer(timer1, 5.0f);
}
void run() {
	timer1 = createTimer(5.0f);
	showTimer(timer1);
	startTimer(timer1);
}
void StartGame() {
	hideObject(startbutton);
	hideObject(endbutton);
	enterScene(scene1_0);
}
void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	defineCombination(book, pensil, dic);
	if (object == startbutton) {
		StartGame();
		showMessage("으음... 여긴 어디지?");
	}
	else if (object == endbutton) {
		endGame();
	}
	else if (object == Scene1) {
		if (x > 500 && x < 800 && y > 560 && y < 660) {
			hideObject(Scene1);
			showObject(act1);
			stopSound(theme);
			playSound(asd);
		}
		else {
			showMessage("방 안을 살펴보자.");
		}
	}
	else if (object == act1) {
		enterScene(scene1_1);
		showMessage("방금 뭐였지..?");
		stopSound(asd);
		playSound(theme);
	}
	else if (object == key) {
		pickObject(key);
	}
	else if (object == Scene1_1) {
		if (x > 500 && x < 800 && y > 500 && y < 660) {
			if (getHandObject() == key) {
				enterScene(scene20);
				playSound(open);
				showMessage("휴, 드디어 복도로 나왔다. 앞으로 가보자");
			}
			else {
				showMessage("열쇠가 있으면 나갈 수 있을 것 같다.");
			}
		}
	}
	else if (object == front1) {
		enterScene(scene21);
		playSound(foot);
	}
	else if (object == front2) {
		enterScene(scene22);
	}
	else if (object == front3) {
		enterScene(scene23);
	}
	else if (object == front4) {
		enterScene(scene24);
		stopSound(foot);
		run();
		showMessage("헉, 저게 뭐지? 빨리 도망가지 않으면 큰일날 것 같다.");
		makeback();
	}
	else if (object == back1) {
		enterScene(run1);
		rest();
		stopSound(foot2);
		showMessage("하아.. 겨우 도망왔다. 이제 어떡하지 ?");
	}
	else if (object == back2) {
		enterScene(scene20);
	}
	else if (object == back3) {
		enterScene(scene21);
	}
	else if (object == back4) {
		enterScene(scene22);
		showMessage("다..?");
	}
	else if (object == back5) {
		enterScene(scene23);
		showMessage("사라졌....");
		hidefront1();
		playSound(foot2);
	}

	else if (object == front5) {
		enterScene(scene31);
		playSound(wolff);
		showMessage("어디선가 늑대 울음소리가 난다 ..");
	}
	else if (object == front6) {
		enterScene(scene32);
		playSound(foot);
	}
	else if (object == front7) {
		enterScene(scene33);
	}
	else if (object == front8) {
		showObject(wolf);
		enterScene(scene34);
		stopSound(foot);
		showMessage("다가가면 위험할 것 같지만 덤비지는 않는다. 클릭해보자");
	}

	else if (object == Run1) {
		showMessage("휴,, 겨우 돌아왔다. 그런데 뭔가 다른데?");
		if (x > 500 && x < 800 && y > 560 && y < 660) {
			enterScene(ask);
			showMessage("여긴..?");
			stopSound(theme);
		}
		else {
			showMessage("나갈 방법을 찾아보자.");
		}
	}
	else if (object == asker) {
		showMessage("다음 문제를 풀면 길이 생길 것이다. 답은 배경을 눌러라");
		enterScene(ask1);
		stopSound(theme);
		playSound(a1);
	}
	else if (object == ask1_1) {
		showKeypad("060518", door1);
	}
	else if (object == door1) {
		showMessage("문제를 풀어라");
	}
	else if (object == door2) {
		if (closed1 == false) {
			enterScene(scene30);
			stopSound(a1);
			playSound(theme);
		}
	}
	else if (object == door3) {
		enterScene(scene40);
		showMessage("휴.. 나왔다. 얼른 밖으로 나가자..");
		stopSound(a2);
		playSound(theme);
	}

	else if (object == wolf) {
		hideObject(wolf);
		showObject(wolf1);
		playSound(wolfff);
	}
	else if (object == wolf1) {
		hideObject(wolf1);
		showObject(wolf2);
		playSound(wolfff);
	}
	else if (object == wolf2) {
		hideObject(wolf2);
		showObject(wolf3);
		playSound(wolfff);
	}
	else if (object == wolf3) {
		hideObject(wolf3);
		showObject(wolf4);
		playSound(wolfff);
	}
	else if (object == wolf4) {
		hideObject(wolf4);
		showObject(front9);
		stopSound(wolfff);
		stopSound(wolff);
		showMessage("이제 앞으로 나아갈 수 있다.");
	}
	else if (object == front9) {
		enterScene(ask2);
		stopSound(theme);
		showMessage("또 만났구나.");
	}
	else if (object == asker2) {
		showMessage("문제를 풀어야만 앞으로 나아갈 수 있다.");
		enterScene(ask2_2);
		playSound(a2);
	}
	else if (object == ask2_3) {
		showKeypad("324768", door3);
	}
	else if (object == Scene40) {
		enterScene(scene41);
		playSound(foot);
		showMessage("앞에 교실이 보인다.");
	}
	else if (object == Scene41) {
		stopSound(foot);
		stopSound(theme);
		playSound(a3);
		enterScene(title2);
	}
	else if (object == class1) {
		if (x > 610 && x < 730 && y > 150 && y < 320) {
			pickObject(book);
			showMessage("책을 얻었다.");
		}
		else if (x > 220 && x < 380 && y < 230 && y > 60) {
			pickObject(pensil);
			showMessage("연필을 얻었다.");
		}
		else if (x > 850 && y > 480) {
			if (closed2 == true) {
				if (getHandObject() == dic) {
					closed2 = false;
					playSound(glass);
					showMessage("나가보자.");
				}
				else {
					showMessage("무거운 것을 던지면 유리를 깰 수 있을 것 같다.");
				}
			}
			else {
				stopSound(a3);
				enterScene(ask3);
			}
		}
		else {
			showMessage("주변을 살펴보자.");
		}
	}
	else if (object == book) {
		pickObject(book);
	}
	else if (object == asker3) {
		showMessage("마지막 문제이니 잘 풀어보아라.");
		enterScene(ask4);
		playSound(a4);
	}
	else if (object == ask4_1) {
		showKeypad("escape", ask4_1);
	}
	else if (object == askerre) {
		pickObject(umb);
		showMessage("비가 오고 있으니 우산을 가져가라.");
		enterScene(exit);
		playSound(theme);
	}
	else if (object == exit1) {
		enterScene(final1);
	}
	else if (object == final2) {
		endGame();
	}
}
void objectCallback(ObjectID object, EventID event) {
	if (object == door1) {
		if (event == EventID::EVENT_KEYPAD) {
			closed1 = false;
			hideObject(door1);
			showObject(door2);
			playSound(open);
			playSound(theme);
			showMessage("정답이다. 문을 열고 나가라. 나중에 또 보도록 하지");
		}
	}
	else if (object == door3) {
		if (event == EventID::EVENT_KEYPAD) {
			showObject(door3);
			playSound(open);
			showMessage("정답이다. 이제 마지막이다.");
		}
	}
	else if (object == ask4_1) {
		if (event == EventID::EVENT_KEYPAD) {
			showMessage("모든 문제를 풀었구나. 이제 나가도 된다.");
			enterScene(askre);
		}
	}
	else if (object == exit1) {
		enterScene(final1);
		stopSound(theme);
	}
}
void timerCallback(TimerID timer) {
	if (timer == timer1) {
		enterScene(ask);
		rest();
		stopSound(foot2);
		stopSound(theme);
		showMessage("으윽.. 여긴 어디지?");
	}
}
int main() {
	setMouseCallback(mouseCallback);
	setTimerCallback(timerCallback);
	setObjectCallback(objectCallback);


	ask = createScene("진실의 방", "질문자.png");
	ask2 = createScene("진실의 방", "질문자.png");

	ask1 = createScene("문제1", "문.png");

	ask2_2 = createScene("문제2", "문2.png");

	askre = createScene("진실의 방", "질문자.png");
	askerre = CreateObject("질문자.png", askre, 0, 0);

	ask3 = createScene("진실의 방", "질문자.png");
	asker3 = CreateObject("질문자.png", ask3, 0, 0);
	ask4 = createScene("진실의방", "문제3.png");
	ask4_1 = CreateObject("문제3.png", ask4, 0, 0);

	exit = createScene("출구.png");
	exit1 = CreateObject("출구.png", exit, 0, 0);
	umb = createObject("우산.png");

	final1 = createScene("final.png");
	final2 = CreateObject("final.png", final1, 0, 0);

	title = createScene("title", "배경.png");
	scene1_0 = createScene("납치", "시작배경.png");
	scene1_1 = createScene("납치", "시작배경.png");
	run1 = createScene("도망", "시작배경.png");
	scene20 = createScene("복도", "복도.png");
	scene21 = createScene("복도", "복도_1.png");
	scene22 = createScene("복도", "복도_2.png");
	scene23 = createScene("복도", "복도_3.png");
	scene24 = createScene("복도", "복도_4.png");

	scene30 = createScene("복도", "복도1.png");
	scene31 = createScene("복도", "복도1_1.png");
	scene32 = createScene("복도", "복도1_2.png");
	scene33 = createScene("복도", "복도1_3.png");
	scene34 = createScene("복도", "복도1_4.png");

	scene40 = createScene("복도", "복도2.png");
	scene41 = createScene("복도", "복도2_1.png");


	startbutton = CreateObject("start.png", title, 590, 70);
	endbutton = CreateObject("end.png", title, 590, 20);
	Scene1 = CreateObject("시작배경.png", scene1_0, 0, 0);
	Scene1_1 = CreateObject("시작배경.png", scene1_1, 0, 0);
	key = CreateObject("열쇠.png", scene1_1, 100, 90);


	Scene20 = CreateObject("복도.png", scene20, 0, 0);
	Scene21 = CreateObject("복도_1.png", scene21, 0, 0);
	Scene22 = CreateObject("복도_2.png", scene22, 0, 0);
	Scene23 = CreateObject("복도_3.png", scene23, 0, 0);
	Scene24 = CreateObject("복도_4.png", scene24, 0, 0);

	Scene40 = CreateObject("복도2.png", scene40, 0, 0);
	Scene41 = CreateObject("복도2_1.png", scene41, 0, 0);

	front1 = CreateObject("앞으로간다.png", scene20, 500, 70);
	front2 = CreateObject("앞으로간다.png", scene21, 500, 70);
	front3 = CreateObject("앞으로간다.png", scene22, 500, 70);
	front4 = CreateObject("앞으로간다.png", scene23, 500, 70);

	front5 = CreateObject("앞으로간다.png", scene30, 500, 70);
	front6 = CreateObject("앞으로간다.png", scene31, 500, 70);
	front7 = CreateObject("앞으로간다.png", scene32, 500, 70);
	front8 = CreateObject("앞으로간다.png", scene33, 500, 70);
	front9 = createObject("앞으로간다.png");
	locateObject(front9, scene34, 500, 70);

	Run1 = CreateObject("시작배경.png", run1, 0, 0);

	asker = CreateObject("질문자.png", ask, 0, 0);
	asker2 = CreateObject("질문자.png", ask2, 0, 0);

	ask1_1 = CreateObject("문.png", ask1, 0, 0);

	ask2_3 = CreateObject("문2.png", ask2_2, 0, 0);

	door1 = CreateObject("문1_1.png", ask1, 410, 0);
	door2 = createObject("문1_1.png");
	locateObject(door2, ask1, 410, 0);

	door3 = createObject("문2_2.png");
	locateObject(door3, ask2_2, 250, 140);

	wolf = createObject("늑대.jpg");
	locateObject(wolf, scene34, 570, 300);

	wolf1 = createObject("늑대1.jpg");
	locateObject(wolf1, scene34, 570, 310);

	wolf2 = createObject("늑대2.jpg");
	locateObject(wolf2, scene34, 570, 320);

	wolf3 = createObject("늑대3.jpg");
	locateObject(wolf3, scene34, 570, 330);

	wolf4 = createObject("늑대4.jpg");
	locateObject(wolf4, scene34, 570, 340);

	scaleObject(key, 0.4f);

	act1 = createObject("배경효과.png");
	locateObject(act1, scene1_0, 0, 0);

	title2 = createScene("title2", "title2.jpg");
	class1 = CreateObject("title2.jpg", title2, 0, 0);
	book = createObject("책.png");
	pensil = createObject("연필.png");
	dic = createObject("사전.png");

	theme = createSound("배경음악.mp3");
	asd = createSound("쾅쾅.mp3");

	foot = createSound("발소리.mp3");
	foot2 = createSound("달리기.mp3");

	wolff = createSound("늑대.mp3");
	wolfff = createSound("낑낑.mp3");

	a1 = createSound("문제1.mp3");
	a2 = createSound("문제2.mp3");
	a3 = createSound("문제3.mp3");
	a4 = createSound("문제4.mp3");

	open = createSound("문소리.mp3");

	glass = createSound("유리.mp3");

	playSound(theme);
	startGame(title);
}