#ifndef RECEIVERWORKER_H
#define RECEIVERWORKER_H

#include <QObject>
#include <QTcpSocket>
#include "data_manager.h"


class ReceiverWorker : public QObject
{
    Q_OBJECT
public:
    ReceiverWorker(Data_Manager* dm, qintptr socketDescriptor);

signals:
    void closeThread();
    void dataStageEND();

public slots:
    void metadataStageSTART();
    void dataStageSTART();

private:
    Data_Manager* dm;
    QTcpSocket* tcpSocket;

    QByteArray sentData;
    QPixmap avatar;

    qint64 msgSize = -1;
    qint64 fileSize = -1;
    qint64 receivedBytes = -1;
    QString fileName;
    QString uniqueID;


};

#endif // RECEIVERWORKER_H
