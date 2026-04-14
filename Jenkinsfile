pipeline {
	agent none

	stages {
		stage('Checkout'){
		agent {label 'docker-arm'}
			steps{
				checkout scm
				echo 'git checkout complete'
			}
		}
		stage('Build Firmware'){
		agent {label 'docker-arm'}
			steps{
				sh 'make'
				stash name: 'firmware', include: 'firmware.hex'
				echo 'firmware build completet'
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
				echo 'Flash completet'
			}
		}
	}
}