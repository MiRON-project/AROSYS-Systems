#!/bin/sh
#--------------------------------------------------------------------------
# Code generated by the SmartSoft MDSD Toolchain
# The SmartSoft Toolchain has been developed by:
#  
# Service Robotics Research Center
# University of Applied Sciences Ulm
# Prittwitzstr. 10
# 89075 Ulm (Germany)
#
# Information about the SmartSoft MDSD Toolchain is available at:
# www.servicerobotik-ulm.de
#
# Please do not modify this file. It will be re-generated
# running the code generator.
#--------------------------------------------------------------------------
#
# start script for device PC1


PID_XTERM="/var/tmp/start-PC1-xterms.pid"
PID_COMPONENT_NAMES="/var/tmp/start-PC1-component-names.pid"

SCRIPT_DIR=`pwd`
SCRIPT_NAME=start-PC1.sh

export SMART_ROOT_DEPLOYMENT=$SCRIPT_DIR

#######
## case
case "$1" in
	    
	    
#########################################################################################
## start
start)

true > $PID_XTERM
true > $PID_COMPONENT_NAMES

echo "Starting scenario..."
date -R

# CONFIGURE NAMING SERVICE
	export SMART_NS_ADDR=localhost:20002

echo "Stopping Naming Service..."
killall AceSmartSoftNamingService &
test -e SMART_NAMES && rm -f SMART_NAMES
sleep 1
echo Starting Naming Service...
rm -f AceSmartSoftNamingService.log
xterm -l -lf AceSmartSoftNamingService.log -title "AceSmartSoftNamingService" -hold -e "export LD_LIBRARY_PATH=$SCRIPT_DIR:\$LD_LIBRARY_PATH; ./NamingService/AceSmartSoftNamingService --ns-port 20002 --ns-dir ./ --ns-file SMART_NAMES --filename=ns_config.ini; echo; echo; echo 'Naming Service exited'; /bin/bash" &
echo $! >> $PID_XTERM
echo AceSmartSoftNamingService >> $PID_COMPONENT_NAMES
sleep 1

## start components
export SMART_IP=localhost
echo "starting components..."

# Component instance ComponentLaserObstacleAvoidTest
echo
echo "############################################"
echo "## Starting component instance ComponentLaserObstacleAvoidTest"
cd $SCRIPT_DIR
echo "executing startstop-hooks-ComponentLaserObstacleAvoidTest.sh (errors might be ignored)"
bash startstop-hooks-ComponentLaserObstacleAvoidTest.sh pre-start
cd $SCRIPT_DIR/ComponentLaserObstacleAvoidTest_data
rm -f "../ComponentLaserObstacleAvoidTest.log"
xterm -l -lf "../ComponentLaserObstacleAvoidTest.log" -title "ComponentLaserObstacleAvoidTest@PC1 Component" -hold -e "export LD_LIBRARY_PATH=$SCRIPT_DIR:\$LD_LIBRARY_PATH; $SCRIPT_DIR/ComponentLaserObstacleAvoidTest -filename=$SCRIPT_DIR/ComponentLaserObstacleAvoidTest.ini; echo; echo; echo 'ComponentLaserObstacleAvoidTest exited.'; echo; /bin/bash --login" &
echo $! >> $PID_XTERM
echo ComponentLaserObstacleAvoidTest >> $PID_COMPONENT_NAMES
cd $SCRIPT_DIR
bash startstop-hooks-ComponentLaserObstacleAvoidTest.sh post-start
echo -e "\n\n\n"

# Component instance ComponentWebots
echo
echo "############################################"
echo "## Starting component instance ComponentWebots"
cd $SCRIPT_DIR
echo "executing startstop-hooks-ComponentWebots.sh (errors might be ignored)"
bash startstop-hooks-ComponentWebots.sh pre-start
cd $SCRIPT_DIR/ComponentWebots_data
rm -f "../ComponentWebots.log"
xterm -l -lf "../ComponentWebots.log" -title "ComponentWebots@PC1 Component" -hold -e "export LD_LIBRARY_PATH=$SCRIPT_DIR:\$LD_LIBRARY_PATH; $SCRIPT_DIR/ComponentWebots -filename=$SCRIPT_DIR/ComponentWebots.ini; echo; echo; echo 'ComponentWebots exited.'; echo; /bin/bash --login" &
echo $! >> $PID_XTERM
echo ComponentWebots >> $PID_COMPONENT_NAMES
cd $SCRIPT_DIR
bash startstop-hooks-ComponentWebots.sh post-start
echo -e "\n\n\n"

# Component instance ComponentWebotsLidarTest
echo
echo "############################################"
echo "## Starting component instance ComponentWebotsLidarTest"
cd $SCRIPT_DIR
echo "executing startstop-hooks-ComponentWebotsLidarTest.sh (errors might be ignored)"
bash startstop-hooks-ComponentWebotsLidarTest.sh pre-start
cd $SCRIPT_DIR/ComponentWebotsLidarTest_data
rm -f "../ComponentWebotsLidarTest.log"
xterm -l -lf "../ComponentWebotsLidarTest.log" -title "ComponentWebotsLidarTest@PC1 Component" -hold -e "export LD_LIBRARY_PATH=$SCRIPT_DIR:\$LD_LIBRARY_PATH; $SCRIPT_DIR/ComponentWebotsLidarTest -filename=$SCRIPT_DIR/ComponentWebotsLidarTest.ini; echo; echo; echo 'ComponentWebotsLidarTest exited.'; echo; /bin/bash --login" &
echo $! >> $PID_XTERM
echo ComponentWebotsLidarTest >> $PID_COMPONENT_NAMES
cd $SCRIPT_DIR
bash startstop-hooks-ComponentWebotsLidarTest.sh post-start
echo -e "\n\n\n"

# Component instance ComponentWebotsPioneer3DX
echo
echo "############################################"
echo "## Starting component instance ComponentWebotsPioneer3DX"
cd $SCRIPT_DIR
echo "executing startstop-hooks-ComponentWebotsPioneer3DX.sh (errors might be ignored)"
bash startstop-hooks-ComponentWebotsPioneer3DX.sh pre-start
cd $SCRIPT_DIR/ComponentWebotsPioneer3DX_data
rm -f "../ComponentWebotsPioneer3DX.log"
xterm -l -lf "../ComponentWebotsPioneer3DX.log" -title "ComponentWebotsPioneer3DX@PC1 Component" -hold -e "export LD_LIBRARY_PATH=$SCRIPT_DIR:\$LD_LIBRARY_PATH; $SCRIPT_DIR/ComponentWebotsPioneer3DX -filename=$SCRIPT_DIR/ComponentWebotsPioneer3DX.ini; echo; echo; echo 'ComponentWebotsPioneer3DX exited.'; echo; /bin/bash --login" &
echo $! >> $PID_XTERM
echo ComponentWebotsPioneer3DX >> $PID_COMPONENT_NAMES
cd $SCRIPT_DIR
bash startstop-hooks-ComponentWebotsPioneer3DX.sh post-start
echo -e "\n\n\n"


cd $SCRIPT_DIR

;; ## start


#########################################################################################
## stop
stop)
cd $SCRIPT_DIR
bash startstop-hooks-ComponentLaserObstacleAvoidTest.sh pre-stop
bash startstop-hooks-ComponentWebots.sh pre-stop
bash startstop-hooks-ComponentWebotsLidarTest.sh pre-stop
bash startstop-hooks-ComponentWebotsPioneer3DX.sh pre-stop

echo "kill all components..."

for I in `cat $PID_COMPONENT_NAMES`; do
        echo $I
        killall -2 $I
done
rm $PID_COMPONENT_NAMES

sleep 3

for I in `cat $PID_XTERM`; do
        echo $I
        kill -2 $I
done
rm $PID_XTERM



test -e SMART_NAMES && rm -f SMART_NAMES

bash startstop-hooks-ComponentLaserObstacleAvoidTest.sh post-stop
bash startstop-hooks-ComponentWebots.sh post-stop
bash startstop-hooks-ComponentWebotsLidarTest.sh post-stop
bash startstop-hooks-ComponentWebotsPioneer3DX.sh post-stop


# collect log files
ls -l *.log && (
	pwd
	tar czvf PC1-logs-$(date +"%Y%m%d%H%M").tar.gz *.log
	rm *.log
)

;; ## stop



#########################################################################################
## menu

menu-start)
	bash $SCRIPT_NAME start
	cd $SCRIPT_DIR
	bash $SCRIPT_NAME menu
;;

menu-stop)
	bash $SCRIPT_NAME stop
	cd $SCRIPT_DIR
	bash $SCRIPT_NAME menu
;;

menu-tile)
	bash tiler.sh
	cd $SCRIPT_DIR
	bash $SCRIPT_NAME menu
;;

menu)

#wmctrl -r :ACTIVE: -b add,above
ACTION=$(whiptail --title "Scenario Control" --menu "Choose an option" 12 35 4 "menu-start" "Start Scenario" "menu-stop" "Stop Scenario" "menu-tile" "Arrange terminals" "quit" "Quit to console" 3>&1 1>&2 2>&3)
#whiptail --title "Scenario Control" --menu "Choose an option" 10 30 3 "menu-start" "Start Scenario" "menu-stop" "Stop Scenario" "quit" "Quit to console" 2>/tmp/whip
#ACTION=`cat /tmp/whip`

cd $SCRIPT_DIR
bash $SCRIPT_NAME $ACTION

;; ## menu

quit)
	bash $SCRIPT_NAME stop
;;
		
		
#########################################################################################
## default
*)
echo "No such parameter: $1"
echo "Usage: $SCRIPT_NAME {start|stop|menu-start|menu-stop|menu}"
exit 1
;;

esac
