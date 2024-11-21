#!/bin/bash

echo "=========================="
echo "Starting App tntc_controller for {APP_PRETTY_NAME}"


systemctl start tntc
systemctl start rosnodeChecker
