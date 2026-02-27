#include <iostream>
#include <vector>
using namespace std;

/// \brief Класс который содержит логику выполнения действий 
class ComputerSystem
{
public:
	void openFile(const string& file) { cout << "Открываем файл: " << file << endl; }
	void shutdown() { cout << "Выключаем компьютер " << endl; }
	void launcherBrowser() { cout << "Запускаем браузер" << endl; }
	void restart() { cout << "Перезагружаем компьютер" << endl; }
};

/// \brief Интерфейс команд
class Commad {
public:
	/**
	* \brief Метод для испольнения команды
	*/
	virtual void execute() = 0;
	/**
	* \brief Метод для отмены действия
	* \remark Просто выводится текст в консоль
	*/
	virtual void undo() = 0;
};

/// \brief Команда открытия файла
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

/// \brief Команда выполнения системы
class ShutdownCommand : public Commad
{
private:
	ComputerSystem* system;
public:
	ShutdownCommand(ComputerSystem* s) : system(s) {}
	void execute() override { system->shutdown(); }
	void undo() override { cout << "Отмена: Включаем компьютер обратно" << endl; }

};

/// \brief Команда запуска браузера
class LaunchBrowserCommand : public Commad
{
private:
	ComputerSystem* system;
public:
	LaunchBrowserCommand(ComputerSystem* s) : system(s) {}
	void execute() override { system->launcherBrowser(); }
	void undo() override { cout << "Закрываем браузер" << endl; }

};

/// \brief Команда перезагрузки 
class RestardCommand : public Commad
{
private:
	ComputerSystem* system;
public:
	RestardCommand(ComputerSystem* s) : system(s) {}
	void execute() override { system->restart(); }
	void undo() override { cout << "Отмена: Выключаем перезагрузку" << endl; }

};


/// \brief Класс инициатор
class RenoteControl
{
private:
	vector<Commad*> commands;
public:
	/**
	* \brief Добавляет команду в очередь выполнения
	* \note Объекты команд должны быть созданы заранее
	*/
	void addCommand(Commad* cmd) { commands.push_back(cmd); }
	/**
	* \brief Последовательно выполняет все накопленные команды
	*/
	void pressButton() {
		for (auto cmd : commands)
		{
			cmd->execute();
		}
	}
	/**
	* \brief Отменяет последнюю добавленную команду
	* \remark Удаляет команду из спсика после отмены
	*/
	void undoLast()
	{
		if (!commands.empty())
		{
			commands.back()->undo();
			commands.pop_back();
		}
	}
};

/// \brief Создание объектов, отмента последнего действия и очистка памяти
int main()
{
	setlocale(LC_ALL, "ru");

	ComputerSystem system;
	
	Commad* openCmd = new openFileCommand(&system, "document.txt");
	Commad* shutdownCmd = new ShutdownCommand(&system);
	Commad* browserCmd = new LaunchBrowserCommand(&system);
	Commad* restardCmd = new RestardCommand(&system);

	RenoteControl remote;
	remote.addCommand(openCmd);
	remote.addCommand(browserCmd);
	remote.addCommand(shutdownCmd);
	remote.addCommand(restardCmd);

	remote.pressButton();
	remote.undoLast();
	delete openCmd;
	delete shutdownCmd;
	delete browserCmd;




}
