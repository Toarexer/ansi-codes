# ANSI escape codes

### Usage:
`./asni [options]`

### Options:
* `b` (binary)
* `o` (octal)
* `d` (decimal)
* `h`/`x` (hexedecimal)

The options can be used together: `./ansi bh` or `./ansi h d o`

> This will print out the binary representation of the number first than the hexedecimal one followed by the test text.

Only the order of the options matter. They can be part of the same argument or even multiple ones.
If an options is used multiple times only it's first appearance will be taken into consideration.
