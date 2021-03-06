# smart-traffic-lights-protocol
A simple binary protocoll for a PoC traffic lights simulation

# Description

## packet

For this simple protocol, the send and receive packet are the same:

| type | name | description |
|---|---|---|
| uint8_t | s_id | id of sender (0=controller) |
| uint8_t | r_id | id of receiver (0=controller |
| uint8_t | c_state | current state of traffic light |
| uint8_t | n_state | next state of traffic light |

The protocol uses no checks. It's supposed to be unreliable and insecure.

## Additional Features

* Add parity bit?
* destination and sender IP? or handle via UDP?

## States

The following states are possible:

|Code|State|
|---|---|
|0001|red|
|0010|red-yellow|
|0100|green|
|1000|green-yellow|
|0111|empty state|

## Example: change traffic light 1 from red to yellow

From controller to light
```
Decimal
 0 | 1 | 1 | 2 |
```

Response from light to controller
```
Decimal
1 | 0 | 2 | 7 | 
```

the light sends the empty state as next state, because it will be determined by the controller

