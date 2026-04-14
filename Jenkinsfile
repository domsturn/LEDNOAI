pipeline {
	agent none

	stages {
		stage('Checkout'){
		agent {label 'docker-arm'}
			steps{
				checkout scm
				stash name: 'workspace', includes: '**/*' //schönheitsding, damit nicht jede stage chackout machen muss
				echo 'git checkout complete'
			}
		}
		stage('Build Firmware'){
		agent {label 'docker-arm'}
			steps{
				unstash 'workspace'
				sh 'make'
				stash name: 'firmware', includes: 'firmware.hex'
				echo 'firmware build completet'
			}
		}
		stage('Flash Arduino'){
		agent {label 'flash-node'}
			steps{
				unstash 'workspace'
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