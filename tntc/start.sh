#!/bin/bash

echo "=========================="
echo "Starting App tntc for {APP_PRETTY_NAME}"


systemctl start tntc
systemctl start rosnodeChecker
