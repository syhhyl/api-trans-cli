CC=clang
CFLAGS=-I/opt/homebrew/include/
LDFLAGS=-L/opt/homebrew/lib -lcurl -lcjson -lcrypto
OBJS=main.o json_parser.o cre_url.o cal_md5_openssl.o http_request.o read_config.o

trans-cli: $(OBJS)
	$(CC) $(OBJS) -o trans-cli $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o trans-cli
