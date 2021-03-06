#ifndef RECEIVERWORKER_H
#define RECEIVERWORKER_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include "data_manager.h"


class ReceiverWorker : public QObject
{
    Q_OBJECT
public:
    ReceiverWorker(Data_Manager* dm, qintptr socketDescriptor);
    ~ReceiverWorker();

signals:
    void closeThread();
    void dataStageEND();// where it is USED????

public slots:
    void metadataStageSTART();
    void pathSelectionSTART(QString);
    void dataStageSTART();
    void receivingStep();

    void onInterruptReceiving(QUuid);
    void on_disconnected();
    void closeConnection();

private:
    Data_Manager* dm;
    QTcpSocket* tcpSocket;
    QFile *file = nullptr;
    QByteArray fileBuffer;

    QByteArray sentData;
    QPixmap avatar;

    qint64 msgSize = -1;
    qint64 fileSize = -1;
    qint64 receivedBytes = 0;
    QString fileName;
    QString uniqueID;

    QAtomicInt atomicFlag = 0;
};

#endif // RECEIVERWORKER_H
