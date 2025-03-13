# Gaming Wheel Arduino Python

This project serves as an interface between a gaming application and an Arduino device, utilizing telemetry data from the F1 racing simulation. The application captures telemetry data from the F1 telemetry client and communicates with an Arduino via a serial connection.

## Project Structure

```
gaming-wheel-arduino-python
├── src
│   ├── main.py          # Entry point of the application
│   ├── udp
│   │   └── parser.py    # Handles telemetry data reception
│   └── serial
│       └── reader.py    # Manages serial communication with Arduino
├── requirements.txt      # Lists project dependencies
└── README.md             # Project documentation
```

## Requirements

To run this project, you need to install the required dependencies. You can do this by running:

```
pip install -r requirements.txt
```

## Usage

1. Connect your Arduino to the appropriate serial port.
2. Run the main application:

```
python src/main.py
```

3. The application will start receiving telemetry data and communicating with the Arduino.

## Dependencies

This project requires the following Python libraries:

- `f1-telemetry-client`: For receiving telemetry data from the F1 simulation.
- `pyserial`: For serial communication with the Arduino.

Make sure to check the `requirements.txt` file for the exact versions needed.

## Contributing

Feel free to contribute to this project by submitting issues or pull requests. Your contributions are welcome!