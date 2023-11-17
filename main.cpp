#include <iostream>
using namespace std;

//���Ű� ȯ���մϴ�
//������ ������
//>
//���� �����ϱ� ������ �����ϱ�
//�����Ͽ����ϴ�.
//���� ��ȯ,�������
//�ο�� �������� �����ϱ�
//�ο����� �����


// ����ü struct

//struct Objection
//{
//	int type;
//	int hp;
//	int attack;
//	int defence;
//};
//
//Objection PlayertInfo;
// {
//
//
// }

int PlayerType;
int hp;
int attack;
int defence;

enum PlayerType
{
	PT_Knigt = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

int MonsterType;
int Monsterhp;
int Monsterattack;
int Monsterdefence;

enum MonsterType
{
	MT_Silme = 1,
	MT_Orc = 2,
	MT_Skeleton = 3
};

//�Լ� ����
void EnterLobby();
void SelecPlayer();
void EnterField();
void CreatorRandomMonster();
void EnterBattle();

int main()
{
	srand(time(0));
	EnterLobby();

 return 0;
}

void SelecPlayer()
{
	while (true)
	{
		cout << "----------------------------" << endl;
		cout << "������ ����ּ���" << endl;
		cout << "���� (1) , �ü� (2) , ������ (3)" << endl;
		cout << ">";

		cin >> PlayerType;

		if (PlayerType == PT_Knigt)
		{
			cout << "��� ������.....!" << endl;
			hp = 200;
			attack = 20;
			defence = 10;
			break;
		}
		else if (PlayerType == PT_Archer)
		{
			cout << "�ü� ������.....!" << endl;
			hp = 150;
			attack = 15;
			defence = 8;
			break;
		}
		else if (PlayerType == PT_Mage)
		{
			cout << "������ ������.....!" << endl;
			hp = 100;
			attack = 30;
			defence = 5;
			break;
		}
	}

}



void EnterLobby()
{
	while (true)
	{
		cout << "----------------------------" << endl;
		cout << "TxT �������� ���Ű��� ȯ���մϴ�" << endl;
		cout << "----------------------------" << endl;
		
		//�÷��̾� ���� ����
		SelecPlayer();

		cout << "----------------------------" << endl;
		cout << "(1)�ʵ�����  (2)���� ����" << endl;
		cout << "----------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}

	}

}

void EnterField()
{
	while (true)
	{

		cout << "----------------------------" << endl;
		cout << "�ʵ忡 �����ϼ˽��ϴ�" << endl;
		cout << "----------------------------" << endl;

		cout << "[player hp =" << hp <<"]" << "[player attack =" << attack << "]" << "[player defence = " << defence << "]" << endl;

		CreatorRandomMonster();

		cout << "----------------------------" << endl;
		cout << "(1)���� ,(2)����" << endl;
		cout << ">" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();
			if (hp == 0)
				return;
		}
		else
		{
			return;
		}
	}

}

void CreatorRandomMonster()
{
	//1~3  �������

	MonsterType = 1 + (rand() % 3);

	switch (MonsterType)
	{
	case  MT_Silme:
		cout << "�������� �����ǰ� �ֽ��ϴ�!   (HP : 15 , ATT : 5 , DEF : 0)" << endl;

		Monsterhp = 15;
		Monsterattack = 5;
		Monsterdefence = 0;
		break;

	case  MT_Orc:
		cout << "��ũ�� �����ǰ� �ֽ��ϴ�!   (HP : 40 , ATT : 10 , DEF : 3)" << endl;

		Monsterhp = 40;
			Monsterattack = 10;
		Monsterdefence = 3;
		break;

	case  MT_Skeleton:
		cout << "���̷����� �����ǰ� �ֽ��ϴ�!   (HP : 80 , ATT : 15 , DEF : 5)" << endl;

		Monsterhp = 80;
		Monsterattack = 15;
		Monsterdefence = 5;
		break;

	}

}

void EnterBattle()
{
	//  �����ϳ��� ����������
	while (true)
	{
		// �÷��̾� ���ݽ�
		int damage = attack - Monsterdefence;
		if (damage < 0)
			damage = 0;

		Monsterhp = Monsterhp - damage;
		if (Monsterhp < 0)
			Monsterhp = 0;

		cout << "������ ���� ä��" <<  Monsterhp<< endl;

		if (Monsterhp == 0)
		{
			cout << "���͸� óġ�߽��ϴ�" << endl;
			return; 
		}

		//���Ͱ� ���ݽ�
		int Monsterdamage = Monsterattack - defence;
		if (Monsterdamage < 0)
			Monsterdamage = 0;

		hp = hp - Monsterdamage;
		if (hp < 0)
			hp = 0;

		cout << "�÷��̾��� ���� ä�� : " << hp << endl;

		if (hp == 0) 
		{
			cout << "����Ͽ����ϴ� ....game over" << endl;
			return;
		}

	}


}