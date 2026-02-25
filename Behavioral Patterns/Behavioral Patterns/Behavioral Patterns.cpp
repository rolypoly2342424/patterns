#include <iostream>
#include <vector>
using namespace std;

class ComputerSystem
{
public:
	void openFile(const string& file) { cout << "Открываем файл: " << file << endl; }
	void shutdown() { cout << "Выключаем компьютер " << endl; }
	void launcherBrowser() { cout << "Запускаем браузер" << endl; }
};

class Commad {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class openFileCommand : public Commad
{
private:
	ComputerSystem* system;
	string fileName;
public:
	openFileCommand(ComputerSystem* s, const string& fn) : system(s), fileName(fn) {}
	void execute() override { system->openFile(fileName); }
	void undo() override { cout << "Закрываем файл " << endl; }

};

class ShutdownCommand : public Commad
{
private:
	ComputerSystem* system;
public:
	ShutdownCommand(ComputerSystem* s) : system(s) {}
	void execute() override { system->shutdown(); }
	void undo() override { cout << "Отмена: Включаем компьютер обратно" << endl; }

};

class LaunchBrowserCommand : public Commad
{
private:
	ComputerSystem* system;
public:
	LaunchBrowserCommand(ComputerSystem* s) : system(s) {}
	void execute() override { system->launcherBrowser(); }
	void undo() override { cout << "Закрываем браузер" << endl; }

};

class RenoteControl
{
private:
	vector<Commad*> commands;
public:
	void addCommand(Commad* cmd) { commands.push_back(cmd); }
	void pressButton() {
		for (auto cmd : commands)
		{
			cmd->execute();
		}
	}
	void undoLast()
	{
		if (!commands.empty())
		{
			commands.back()->undo();
			commands.pop_back();
		}
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	ComputerSystem system;
	
	Commad* openCmd = new openFileCommand(&system, "document.txt");
	Commad* shutdownCmd = new ShutdownCommand(&system);
	Commad* browserCmd = new LaunchBrowserCommand(&system);

	RenoteControl remote;
	remote.addCommand(openCmd);
	remote.addCommand(browserCmd);
	remote.addCommand(shutdownCmd);

	remote.pressButton();
	remote.undoLast();
	delete openCmd;
	delete shutdownCmd;
	delete browserCmd;




}
