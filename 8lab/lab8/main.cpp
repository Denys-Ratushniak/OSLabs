#include <QApplication>
#include <QCoreApplication>
#include <bits/stdc++.h>
#include <QFileDialog>
#include <qdebug.h>
#include <QProcess>
#include <pthread.h>
#include <sys/resource.h>
#include <signal.h>
#include <sys/wait.h>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString fileName = QFileDialog::getExistingDirectory(nullptr, ("Open File"),"/home");
    std::string beb = fileName.toStdString();

    QString command = "tar -zcf test.tar.gz " + fileName;

    QProcess process;
    process.start(command);
    qint64 pid =  process.processId();
    cout << pid << endl;

    int be = getpriority(PRIO_PROCESS, pid);

    cout << "STOP" << endl;
    kill(pid, SIGSTOP);

    long long b = 0;
    while(b<=30000000000) b++;
    //kill(pid, SIGINT);
    kill(pid, SIGCONT);
    cout << "GO" << endl;

    setpriority(PRIO_PROCESS, pid, 19);

    return a.exec();
}
