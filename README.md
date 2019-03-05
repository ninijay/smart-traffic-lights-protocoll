# smart-traffic-lights-protocol
A simple binary protocoll for a PoC traffic lights simulation

# Description

## packet

For this simple protocol, the send and receive packet are the same:

| Offset | type | name | description |
|---|---|---|---|
| 0 | uint32_t| size | size of packet |
| 5 | uint8_t | s_id | id of sender (0=controller) |
| 9 | uint8_t | r_id | id of receiver (0=controller |
| 13 | uint8_t | c_state | current state of traffic light |
| 17  | uint8_t | n_state | next state of traffic light |
| 21 | <- total size | | |

The protocol uses no checks. It's supposed to be unreliable and insecure.

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
21 | 0 | 1 | 1 | 2 |
```

Response from light to controller
```
Decimal
21 | 1 | 0 | 2 | 7 | 
```

the light sends the empty state as next state, because it will be determined by the controller

