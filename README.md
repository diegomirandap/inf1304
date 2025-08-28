# inf1304
Aulas de INF-1304 - Distribuição e concorrência

cd containers/chatapp
./start.sh
docker ps -a
cd frontend (em dois terminais)
python chat_listener.py / python chat_sender.py


docker run -it ubuntu:24.04
apt update
apt install net-tools
ifconfig

exibir logs do container:
docker logs -f chat-app-kafka-1

acessar container de forma iterativa:
docker exec -it chat-app-zookeeper-1 /bin/bash
apt update
apt install net-tools
ifconfig


topologia inicial VS topologia ideal

zk-172.19.0.2/16           |         prod-172.19.0.5/16
    2181(porta exposta)    |            8080(porta corretamente exposta)
kf-172.19.0.3/16           |         cons-172.19.0.4/16
    9092(porta exposta)    |            8081(porta corretamente exposta) (Port Address Translator(internamente é 8080))

                           |
                           |
                           V

              ext-net            int-net
                 |                  |     
                 |-------prod-------|
                 |        zk--------|     
                 |-------cons-------|
                 |        kf--------|
     world-------|

