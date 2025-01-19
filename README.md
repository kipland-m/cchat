# CChat

This repository contains a simple server-client chat application implemented in C.

## Files
- `server.c`: The server-side application.
- `client.c`: The client-side application.

## Requirements
- GCC or any compatible C compiler.
- Linux or a Unix-like operating system.

## Compilation
To compile the server and client programs, use the following commands:

```bash
# Compile the server
gcc -o server server.c

# Compile the client
gcc -o client client.c
```

## Usage
### Start the Server
Run the following command to start the server:
```bash
./server
```
The server listens for connections on port `9999`.

### Start the Client
Run the following command to start the client:
```bash
./client
```
The client connects to the server on `localhost` and port `9999`.

### Interaction
- **In Client:** Type messages into the client's terminal to send them to the server.
- Messages received from the other end are displayed in the respective terminal.

### Notes
- Ensure both server and client programs are running simultaneously for proper communication.
- Use `Ctrl+C` to terminate the server and client programs.

## How It Works
- The server listens for incoming connections on a specified port (9999).
- When the client connects, the server accepts the connection.
- Both programs use `poll()` to monitor `stdin` and the socket file descriptor for input.
- Messages are sent using `send()` and received using `recv()`.

## Example
1. Start the server:
   ```bash
   ./server
   ```
2. Start the client:
   ```bash
   ./client
   ```
4. Type a message in the client terminal and press Enter. The message will appear in the server terminal.
