

# TCP-Ping

A simple utility to test TCP connectivity to a specified host and port. This tool measures the round-trip time (RTT) for establishing a TCP connection to a target server, similar to how `ping` measures the latency with ICMP packets, but for TCP connections.

This can be useful for testing the availability of services running on specific ports (e.g., web servers, database servers, etc.).

## Features

- Tests TCP connectivity to a specific hostname/IP address and port.
- Measures the round-trip time (RTT) for the TCP connection.
- Provides colored output for better readability (success, errors, connection attempts).
- Supports both IPv4 and IPv6 addresses.

## Installation

### Prerequisites

- A C++ compiler supporting C++11 or later (e.g., `g++`).
- POSIX-compliant system (Linux, macOS).
- `make` utility (optional for convenience).

### Compile

You can compile the source code manually using `g++`:

```bash
g++ -o tcp_ping tcp_ping.cpp
```

Alternatively, if you have a `Makefile` in the project, you can simply run:

```bash
make
```

This will generate the executable file `tcp_ping`.

## Usage

The program requires two arguments:
- **hostname**: The target hostname or IP address.
- **port**: The TCP port to test.

### Command-line Example:

```bash
./tcp_ping <hostname> <port>
```

For example, to check TCP connectivity to `example.com` on port 80 (HTTP):

```bash
./tcp_ping example.com 80
```

### Sample Output:

```bash
Resolving hostname example.com...
Connecting to example.com:80...
Connected to example.com:80 in 32 ms
```

If the connection fails, you will see an error message in red, indicating the failure to connect.

## Colored Output

- **Blue**: Info messages (e.g., resolving hostname).
- **Yellow**: Status messages (e.g., connecting...).
- **Green**: Success messages (e.g., connection established).
- **Red**: Error messages (e.g., connection failed).


## Contributing

Contributions, bug reports, and feature requests are welcome! Please feel free to open an issue or submit a pull request on the GitHub repository.

---
