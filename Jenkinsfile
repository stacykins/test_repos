pipeline {
    agent any

    environment {
        VS_PATH = '"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe"'
        SOLUTION = 'test_repos.sln'
        CONFIG = 'Debug'
    }

    stages {
        stage('Checkout SCM') {
            steps {
                checkout scm
            }
        }

        stage('Restore NuGet Packages') {
            steps {
                echo 'Restoring NuGet packages via MSBuild...'
                bat '%VS_PATH% %SOLUTION% /p:Configuration=%CONFIG% /m /restore'
            }
        }

        stage('Build') {
            steps {
                echo 'Building solution...'
                bat '%VS_PATH% %SOLUTION% /p:Configuration=%CONFIG% /m'
            }
        }

        stage('Test') {
            steps {
                echo 'Skipping tests for now (GoogleTest/xUnit not configured yet)'
            }
        }
    }

    post {
        always {
            echo 'Pipeline finished'
        }
        failure {
            echo 'Build failed!'
        }
        success {
            echo 'Build succeeded!'
        }
    }
}

