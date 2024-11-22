#!/bin/bash

echo "=========================="
echo "Removing App tntc"


LIBPANDA_USER=$(cat /etc/libpanda.d/libpanda_usr)

# Disable the installed services:
echo " - Disabling startup scripts..."
systemctl disable tntc


# Here is where we remove scripts, services, etc.
echo " - Removing scripts..."
cd
if [ "x"`systemctl list-units | grep -c tntc.service` = "x1" ]; then
    echo "Uninstalling tntc.service"

    source /home/$LIBPANDA_USER/catkin_ws/devel/setup.bash
    rosrun robot_upstart uninstall tntc
fi

systemctl daemon-reload # if needed
