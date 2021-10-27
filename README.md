# minitalk

This Repositorie contains my solution to the project `minitalk` of 42 (Paris).

[![jaeskim's 42 stats](https://badge42.herokuapp.com/api/stats/cmaginot?cursus=42cursus&privacyName=true)](https://github.com/JaeSeoKim/badge42)

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/cmaginot/minitalk)](https://github.com/JaeSeoKim/badge42)

## Using minitalk

### Cloning

```shell
git clone --recurse-submodules https://github.com/Freya-Tenebrae/Minitalk.git
```

### Compilation

```shell
make
```
or
```shell
make bonus
```
to compile the bonuses

### Exemple of uses


In one terminal use the command 

```shell
./server
```

It'll show the PID of the server and will wait any message from a client. It'll look like this
```shell
./server
Server PID : 14626

```
In an other terminal, use the command (after replacing the first argument by the correct PID)
```shell
./client 14569 "This is a test send by the 1rst Client."
```
you can used multiple client without restart the server
```shell
./client 14569 "This is a second test send by the 2nd Client."
./client 14569 "This is a thirst test send by the 3nd Client."
./client 14569 "This is a fourth test send by the 4nd Client."
```

The first terminal will look like this :
```shell
./server
Server PID : 14626
This is a test send by the 1rst Client.
This is a second test send by the 2nd Client.
This is a thirst test send by the 3nd Client.
This is a fourth test send by the 4nd Client.
```

> For the bonus part you just need to change `./server` by `./server_bonus` and `./client` by `./client_bonus`

#### Usefull Link

[Text generator](https://www.blindtextgenerator.com/lorem-ipsum) that I used to test my program
