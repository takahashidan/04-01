#include <iostream>
using namespace std;

// ����N���X
class MyClass {
public:
	void Update();

	void StatusA ();
	void StatusB ();
	void StatusC ();

	// �����o�֐��|�C���^�̃e�[�u��
	static void (MyClass::*table[])();

private:
	// �����o�֐��|�C���^�̃e�[�u�����Q�Ƃ���C���f�b�N�X
	int index = 0;
};

void MyClass::StatusA () { cout << "�G�̐ڋ߁I" << endl; }

void MyClass::StatusB () { cout << "�G�̍U���I" << endl; }

void MyClass::StatusC () { cout << "�G�̌�ށI" << endl; }

void MyClass::Update () {

	// �֐��|�C���^�̃e�[�u������֐������s
	(this->*table[index])();

	int kazu;
	puts("���̍s����");
	scanf_s("%d", &kazu);

	if (kazu == 0) {
		index++;

		if (index > 2) 
			index = 0;
	}
}

// static�Ő錾���������o�֐��|�C���^�e�[�u���̎���
void (MyClass::*MyClass::table[])() = {
    &MyClass::StatusA, // �C���f�b�N�X�ԍ�1
    &MyClass::StatusB, // �C���f�b�N�X�ԍ�1
    &MyClass::StatusC,  // �C���f�b�N�X�ԍ�2
};

int main() {
	MyClass my;

	while (1) {
		my.Update();
	}
	return 0;
}