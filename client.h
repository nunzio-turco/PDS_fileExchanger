#ifndef CLIENT_H
#define CLIENT_H


#include <QObject>
#include <QDebug>
#include <QHostAddress>
#include <QNetworkAddressEntry>
#include <QTcpSocket>
#include <QTcpServer>
#include <QUdpSocket>
#include <QtConcurrent/QtConcurrent>
#include <QThread>
#include "data_manager.h"
#include "senderworker.h"


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(Data_Manager *dm, QObject *parent = nullptr);
    ~Client();

public slots:
    void on_UdpReceive();
    void sendFile();

    void onQuittingApplication();


private:
    Data_Manager *dm = nullptr;
    //QTcpSocket *tcpSocket;
    QUdpSocket *udpSocket;
    QThread *broadcastThread;

    void hello();
    void sendAvatar(QHostAddress);
    void sendMetadataToUser(Host h);
    void sendingFile(QTcpSocket* tcpSocket, QFile* file, Host h);
    QHostAddress findBroadcastAddress();

    QHostAddress broadcastAddress;
    QTcpSocket *broadcastTcpSocket;

    QAtomicInt atomicLoopFlag = 1;

};

#endif // CLIENT_H
