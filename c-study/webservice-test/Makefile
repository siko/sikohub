GSOAP_ROOT=/usr/local/gsoap
WSNAME=add
CC=g++ -g -DWITH_NONAMESPACES
INCLUDE=-I $(GSOAP_ROOT)
SERVER_OBJS=$(WSNAME)C.o $(WSNAME)Server.o stdsoap2.o
CLIENT_OBJS=$(GSOAP_ROOT)/env/envC.o $(WSNAME)ClientLib.o stdsoap2.o
ALL_OBJS=${WSNAME}server.o $(WSNAME)C.o $(WSNAME)Server.o ${WSNAME}test.o 
${WSNAME}client.o $(WSNAME)ClientLib.o
#总的目标
all:server
${WSNAME}.wsdl:${WSNAME}.h
$(GSOAP_ROOT)/soapcpp2 -p$(WSNAME) -i -n -c ${WSNAME}.h
stdsoap2.o:$(GSOAP_ROOT)/stdsoap2.c
$(CC) -c $?
#编译一样生成规则的.o文件
$(ALL_OBJS):%.o:%.c
$(CC) -c $? $(INCLUDE)
#编译服务器端
server:Makefile ${WSNAME}.wsdl ${WSNAME}server.o $(SERVER_OBJS)
$(CC) ${WSNAME}server.o $(SERVER_OBJS) -o ${WSNAME}server
#编译客户端
client:Makefile ${WSNAME}.wsdl ${WSNAME}client.c ${WSNAME}test.c $(ALL_OBJS) stdsoap2.o
$(CC) ${WSNAME}test.o ${WSNAME}client.o $(CLIENT_OBJS) -o ${WSNAME}test
cl:
rm -f *.o *.xml *.a *.wsdl *.nsmap $(WSNAME)H.h $(WSNAME)C.c $(WSNAME)Server.c $(WSNAME)Client.c 
$(WSNAME)Stub.* $(WSNAME)$(WSNAME)Proxy.* $(WSNAME)$(WSNAME)Object.* $(WSNAME)ServerLib.c 
$(WSNAME)ClientLib.c $(WSNAME)server ns.xsd $(WSNAME)test



