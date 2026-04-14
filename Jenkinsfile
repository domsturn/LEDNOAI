pipeline {
	agent none
	options{
		skipDefaultCheckout(true) //Das der Checkout nur einmal am anfang gemacht werden muss
	}

	stages {
		stage('Checkout'){
		agent {label 'docker-arm'}
			steps{
				checkout scm
				echo '##################### git checkout complete #####################'
			}
		}
		stage('Build Firmware'){
		agent {label 'docker-arm'}
			steps{
				sh 'make firmware.hex'
				stash name: 'firmware', includes: 'firmware.hex'
				echo '##################### firmware build completet #####################'
			}
		}
		stage('Flash Arduino'){
		agent {label 'flash-node'}
			steps{
				unstash 'firmware'
				sh'''
				chmod +x scripts/flashskript.sh
				./scripts/flashskript.sh
				'''
				echo '################### Flash completet #####################'
			}
		}
	}
}